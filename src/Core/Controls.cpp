#include <Blob/Core/Controls.hpp>

// #include <imgui.h>
#include <Blob/GLFW.hpp>

namespace Blob::Core {

std::string Key::getName() const {
    const char *name = nullptr; // glfwGetKeyName(id - 1, 0);

    if (name == nullptr)
        return std::string();
    else
        return std::string(name);
}

Keyboard::Keyboard(bool (&keys)[512])
    : UNKNOWN(GLFW::Keys::UNKNOWN, keys), SPACE(GLFW::Keys::SPACE, keys), APOSTROPHE(GLFW::Keys::APOSTROPHE, keys), COMMA(GLFW::Keys::COMMA, keys),
      MINUS(GLFW::Keys::MINUS, keys), PERIOD(GLFW::Keys::PERIOD, keys), SLASH(GLFW::Keys::SLASH, keys), Zero(GLFW::Keys::Zero, keys),
      One(GLFW::Keys::One, keys), Two(GLFW::Keys::Two, keys), Three(GLFW::Keys::Three, keys), Four(GLFW::Keys::Four, keys),
      Five(GLFW::Keys::Five, keys), Six(GLFW::Keys::Six, keys), Seven(GLFW::Keys::Seven, keys), Eight(GLFW::Keys::Eight, keys),
      Nine(GLFW::Keys::Nine, keys), SEMICOLON(GLFW::Keys::SEMICOLON, keys), EQUAL(GLFW::Keys::EQUAL, keys), A(GLFW::Keys::A, keys),
      B(GLFW::Keys::B, keys), C(GLFW::Keys::C, keys), D(GLFW::Keys::D, keys), E(GLFW::Keys::E, keys), F(GLFW::Keys::F, keys), G(GLFW::Keys::G, keys),
      H(GLFW::Keys::H, keys), I(GLFW::Keys::I, keys), J(GLFW::Keys::J, keys), K(GLFW::Keys::K, keys), L(GLFW::Keys::L, keys), M(GLFW::Keys::M, keys),
      N(GLFW::Keys::N, keys), O(GLFW::Keys::O, keys), P(GLFW::Keys::P, keys), Q(GLFW::Keys::Q, keys), R(GLFW::Keys::R, keys), S(GLFW::Keys::S, keys),
      T(GLFW::Keys::T, keys), U(GLFW::Keys::U, keys), V(GLFW::Keys::V, keys), W(GLFW::Keys::W, keys), X(GLFW::Keys::X, keys), Y(GLFW::Keys::Y, keys),
      Z(GLFW::Keys::Z, keys), LEFT_BRACKET(GLFW::Keys::LEFT_BRACKET, keys), BACKSLASH(GLFW::Keys::BACKSLASH, keys),
      RIGHT_BRACKET(GLFW::Keys::RIGHT_BRACKET, keys), GRAVE_ACCENT(GLFW::Keys::GRAVE_ACCENT, keys), WORLD_1(GLFW::Keys::WORLD_1, keys),
      WORLD_2(GLFW::Keys::WORLD_2, keys), ESCAPE(GLFW::Keys::ESCAPE, keys), ENTER(GLFW::Keys::ENTER, keys), TAB(GLFW::Keys::TAB, keys),
      BACKSPACE(GLFW::Keys::BACKSPACE, keys), INSERT(GLFW::Keys::INSERT, keys), DELETE(GLFW::Keys::DEL, keys), RIGHT(GLFW::Keys::RIGHT, keys),
      LEFT(GLFW::Keys::LEFT, keys), DOWN(GLFW::Keys::DOWN, keys), UP(GLFW::Keys::UP, keys), PAGE_UP(GLFW::Keys::PAGE_UP, keys),
      PAGE_DOWN(GLFW::Keys::PAGE_DOWN, keys), HOME(GLFW::Keys::HOME, keys), END(GLFW::Keys::END, keys), CAPS_LOCK(GLFW::Keys::CAPS_LOCK, keys),
      SCROLL_LOCK(GLFW::Keys::SCROLL_LOCK, keys), NUM_LOCK(GLFW::Keys::NUM_LOCK, keys), PRINT_SCREEN(GLFW::Keys::PRINT_SCREEN, keys),
      PAUSE(GLFW::Keys::PAUSE, keys), F1(GLFW::Keys::F1, keys), F2(GLFW::Keys::F2, keys), F3(GLFW::Keys::F3, keys), F4(GLFW::Keys::F4, keys),
      F5(GLFW::Keys::F5, keys), F6(GLFW::Keys::F6, keys), F7(GLFW::Keys::F7, keys), F8(GLFW::Keys::F8, keys), F9(GLFW::Keys::F9, keys),
      F10(GLFW::Keys::F10, keys), F11(GLFW::Keys::F11, keys), F12(GLFW::Keys::F12, keys), F13(GLFW::Keys::F13, keys), F14(GLFW::Keys::F14, keys),
      F15(GLFW::Keys::F15, keys), F16(GLFW::Keys::F16, keys), F17(GLFW::Keys::F17, keys), F18(GLFW::Keys::F18, keys), F19(GLFW::Keys::F19, keys),
      F20(GLFW::Keys::F20, keys), F21(GLFW::Keys::F21, keys), F22(GLFW::Keys::F22, keys), F23(GLFW::Keys::F23, keys), F24(GLFW::Keys::F24, keys),
      F25(GLFW::Keys::F25, keys), NumericKeypadZero(GLFW::Keys::NumericKeypadZero, keys), NumericKeypadOne(GLFW::Keys::NumericKeypadOne, keys),
      NumericKeypadTwo(GLFW::Keys::NumericKeypadTwo, keys), NumericKeypadThree(GLFW::Keys::NumericKeypadThree, keys),
      NumericKeypadFour(GLFW::Keys::NumericKeypadFour, keys), NumericKeypadFive(GLFW::Keys::NumericKeypadFive, keys),
      NumericKeypadSix(GLFW::Keys::NumericKeypadSix, keys), NumericKeypadSeven(GLFW::Keys::NumericKeypadSeven, keys),
      NumericKeypadEight(GLFW::Keys::NumericKeypadEight, keys), NumericKeypadNine(GLFW::Keys::NumericKeypadNine, keys),
      NumericKeypadDECIMAL(GLFW::Keys::NumericKeypadDECIMAL, keys), NumericKeypadDIVIDE(GLFW::Keys::NumericKeypadDIVIDE, keys),
      NumericKeypadMULTIPLY(GLFW::Keys::NumericKeypadMULTIPLY, keys), NumericKeypadSUBTRACT(GLFW::Keys::NumericKeypadSUBTRACT, keys),
      NumericKeypadADD(GLFW::Keys::NumericKeypadADD, keys), NumericKeypadENTER(GLFW::Keys::NumericKeypadENTER, keys),
      NumericKeypadEQUAL(GLFW::Keys::NumericKeypadEQUAL, keys), LEFT_SHIFT(GLFW::Keys::LEFT_SHIFT, keys),
      LEFT_CONTROL(GLFW::Keys::LEFT_CONTROL, keys), LEFT_ALT(GLFW::Keys::LEFT_ALT, keys), LEFT_SUPER(GLFW::Keys::LEFT_SUPER, keys),
      RIGHT_SHIFT(GLFW::Keys::RIGHT_SHIFT, keys), RIGHT_CONTROL(GLFW::Keys::RIGHT_CONTROL, keys), RIGHT_ALT(GLFW::Keys::RIGHT_ALT, keys),
      RIGHT_SUPER(GLFW::Keys::RIGHT_SUPER, keys), MENU(GLFW::Keys::MENU, keys) {}


std::list<KeyboardEvents *> KeyboardEvents::keyUpdates;

/*
void Controller::controllerOut() const {
    ImGui::Begin(name.c_str());

    for (int i = 0; i < joystickAxesCount; i++)
        ImGui::SliderFloat((std::string("Axe :") + std::to_string(i)).c_str(), (float *) &joystickAxes[i], -1.0f, 1.0f, "%.2f");

    for (int i = 0; i < buttonsCount; i++) {
        ImGui::Checkbox((std::string("B") + std::to_string(i + 1)).c_str(), (bool *) &buttons[i]);
        if ((i + 1) % 5 != 0)
            ImGui::SameLine();
    }

    ImGui::End();
}
*/
} // namespace Blob::Core