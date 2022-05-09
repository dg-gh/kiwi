#ifndef KIWI_INCLUDES_HPP
#define KIWI_INCLUDES_HPP

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif // GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef _KIWI_RESTRICT

#ifdef _MSC_VER
#define _KIWI_RESTRICT __restrict
#elif defined(__GNUC__) || defined(__clang__)
#define _KIWI_RESTRICT __restrict__
#else
#define _KIWI_RESTRICT
#endif // COMPILER CHOICE

#endif // KIWI_RESTRICT

#include <string>
#include <vector>
#include <functional>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <cmath>
#include <cstdint>

#include "kiwi_global_type.hpp"

#endif // KIWI_INCLUDES_HPP