#pragma once

#include <Blob/Geometrie.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Collision/Reaction.hpp>

#include <deque>
#include <list>
#include <unordered_map>

namespace Blob::Collision {

    class CollisionDetector;

    /**
     * Object is a virtual class
     * An object have a type to define him and can be hit
     */
    class Object : virtual public Form {
        friend CollisionDetector;
    private:
        int objectType;

    protected:
        /**
         * To set the type of the object
         * The type is used to define the child class of this Object.
         * Typic
         * @param objectType
         */
        void setObjectType(int objectType) {
            Object::objectType = objectType;
        }

        explicit Object(int objectType) : objectType(objectType) {}

        virtual void hit(int objectType, Object &object) {}
    };

    class DynamicObject : public Object {
        friend CollisionDetector;
    private:
        Reaction reaction = STOP;

    protected:
        Vec2f speed{};

        explicit DynamicObject(int objectType) : Object(objectType) {}

        /**
         * Set the reaction when you hit an object.
         * Can bet set in 'hit' to set the reaction of the current collision or in the constructor if you know you will
         * only use one reaction type.
         *
         * The default value is 'STOP'
         *
         * @param reaction
         */
        void setReaction(Reaction reaction) {
            this->reaction = reaction;
        }

        /**
         * This method is used to stop the dynamic object from moving.
         * it will be called each time the collision detector move the target.
         * For example, you can implement this method to return false when the object have reach the destination.
         *
         * @return return true to keep moving or false to stop
         */
        virtual bool moove() {
            return true;
        };

        /**
         * This method is called right before the collision is computed.
         * It's the perfect moment to set the final speed
         */
        virtual void preCollisionUpdate() {}

        /**
         * This method is called right after the collision is computed
         * It can be used to check is you had a collision during this move.
         * For example if 'hit' has not been called between 'preCollisionUpdate' and 'postCollisionUpdate'.
         */
        virtual void postCollisionUpdate() {}
    };

    class CircleStatic : public Object {
        friend CollisionDetector;
    private:
        std::list<CircleStatic *>::iterator elementIt{};
    protected:
        Circle mainCircle{};

        void enableCollision();

        void disableCollision();

        explicit CircleStatic(const int objectType) : Object(objectType) {
            enableCollision();
        }

        ~CircleStatic() {
            disableCollision();
        }
    };

    class CircleDynamic : public DynamicObject {
        friend CollisionDetector;
    private:
        std::list<CircleDynamic *>::iterator elementIt{};
    protected:
        Circle mainCircle{};

        void enableCollision();

        void disableCollision();

        explicit CircleDynamic(const int objectType) : DynamicObject(objectType) {
            enableCollision();
        }

        ~CircleDynamic() {
            disableCollision();
        }
    };

    class RectStatic : public Object, private Rectangle {
        friend CollisionDetector;
    private:
        std::list<RectStatic *>::iterator elementIt{};
    protected:

        void enableCollision();

        void disableCollision();

        explicit RectStatic(Vec2f position, Vec2f size, const int objectType) :
                Rectangle(position, size),
                Object(objectType) {
            enableCollision();
        }

        ~RectStatic() {
            disableCollision();
        }
    };

    class RectDynamic : public DynamicObject, public Rectangle {
        friend CollisionDetector;
    private:
        std::list<RectDynamic *>::iterator elementIt{};
    protected:

        void enableCollision();

        void disableCollision();

        explicit RectDynamic(const int objectType) : DynamicObject(objectType) {
            enableCollision();
        }

        ~RectDynamic() {
            disableCollision();
        }
    };

    class LineStatic : public Object {
        friend CollisionDetector;
    private:
        std::list<LineStatic *>::iterator elementIt{};
    protected:
        std::deque<Point2f> lines{};

        void enableCollision();

        void disableCollision();

        explicit LineStatic(const int objectType) : Object(objectType) {
            enableCollision();
        }

        ~LineStatic() {
            disableCollision();
        }
    };

    class CollisionDetector {
        friend CircleStatic;
        friend CircleDynamic;
        friend RectStatic;
        friend RectDynamic;
        friend LineStatic;
    private:

        static std::unordered_map<int64_t, std::list<Object *>> spacialHash;

        static std::list<CircleStatic *> circleStaticList;
        static std::list<CircleDynamic *> circleDynamicList;
        static std::list<RectStatic *> rectStaticList;
        static std::list<RectDynamic *> rectDynamicList;
        static std::list<LineStatic *> lineStaticList;

        float timeFlow;

        bool timeStoped = false;

        void computeLocalCollision(RectDynamic &object, const std::list<Object *> &targets, Blob::Vec2f frameMove);

    public:

        //StaticObject *getClosetObject(Circle &object, Vec2f frameMove, Hit &hit);

        //void checkCollision(CircleDynamic &object);

        void checkCollision(RectDynamic &object);

        void update();

        void pause();

        void unpause();
    };
}