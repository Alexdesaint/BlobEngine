#pragma once

#include <utility>
#include <exception>
#include <string>

namespace Blob::Core {
    class Exception : public std::exception {
    private:
        const std::string errorMsg;

    public:
        //explicit Exception(const char *errorMsg) : errorMsg(errorMsg){}

        explicit Exception(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

        [[nodiscard]] const char *what() const noexcept override {
            return errorMsg.c_str();
        }
    };
}