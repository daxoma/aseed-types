#pragma once

namespace aseed {
namespace types {

#define EXISTENCE_FUNCTION(inspectorName, methodName)                            \
  template <typename _Rt = void, typename... _ARgs>                              \
  class inspectorName {                                                          \
    struct _Checker {                                                            \
      template <_Rt (*f)(_ARgs...) = &methodName>                                \
      static short check(void*);                                                 \
      static char check(...);                                                    \
    };                                                                           \
                                                                                 \
   public:                                                                       \
    const static bool value = sizeof(_Checker::check(nullptr)) == sizeof(short); \
  };                                                                             \
  template <typename _Rt = void, typename... _ARgs>                              \
  static constexpr bool inspectorName##_v = inspectorName<_Rt, _ARgs...>::value  // EXISTENCE_FUNCTION

#define EXISTENCE_MEMBER_FUNCTION(inspectorName, methodName)                             \
  template <typename _Cl, typename _Rt = void, typename... _ARgs>                        \
  class inspectorName {                                                                  \
    struct _Checker {                                                                    \
      template <typename _Ty, _Rt (_Ty::*f)(_ARgs...) = &_Ty::methodName>                \
      static short check(int);                                                           \
      template <typename _Ty>                                                            \
      static char check(float);                                                          \
    };                                                                                   \
                                                                                         \
   public:                                                                               \
    const static bool value = sizeof(_Checker::template check<_Cl>(0)) == sizeof(short); \
  };                                                                                     \
  template <typename _Ty, typename _Rt = void, typename... _ARgs>                        \
  static constexpr bool inspectorName##_v = inspectorName<_Ty, _Rt, _ARgs...>::value  // EXISTENCE_MEMBER_FUNCTION

#define EXISTENCE_CONST_MEMBER_FUNCTION(inspectorName, methodName)                       \
  template <typename _Cl, typename _Rt = void, typename... _ARgs>                        \
  class inspectorName {                                                                  \
    struct _Checker {                                                                    \
      template <typename _Ty, _Rt (_Ty::*f)(_ARgs...) const = &_Ty::methodName>          \
      static short check(int);                                                           \
      template <typename _Ty>                                                            \
      static char check(float);                                                          \
    };                                                                                   \
                                                                                         \
   public:                                                                               \
    const static bool value = sizeof(_Checker::template check<_Cl>(0)) == sizeof(short); \
  };                                                                                     \
  template <typename _Ty, typename _Rt = void, typename... _ARgs>                        \
  static constexpr bool inspectorName##_v = inspectorName<_Ty, _Rt, _ARgs...>::value  // EXISTENCE_CONST_MEMBER_FUNCTION

#define EXISTENCE_CONST_NOEXCEPT_MEMBER_FUNCTION(inspectorName, methodName)              \
  template <typename _Cl, typename _Rt = void, typename... _ARgs>                        \
  class inspectorName {                                                                  \
    struct _Checker {                                                                    \
      template <typename _Ty, _Rt (_Ty::*f)(_ARgs...) const noexcept = &_Ty::methodName> \
      static short check(int);                                                           \
      template <typename _Ty>                                                            \
      static char check(float);                                                          \
    };                                                                                   \
                                                                                         \
   public:                                                                               \
    const static bool value = sizeof(_Checker::template check<_Cl>(0)) == sizeof(short); \
  };                                                                                     \
  template <typename _Ty, typename _Rt = void, typename... _ARgs>                        \
  static constexpr bool inspectorName##_v = inspectorName<_Ty, _Rt, _ARgs...>::value  // EXISTENCE_CONST_NOEXCEPT_MEMBER_FUNCTION

#define EXISTENCE_NOEXCEPT_MEMBER_FUNCTION(inspectorName, methodName)                    \
  template <typename _Cl, typename _Rt = void, typename... _ARgs>                        \
  class inspectorName {                                                                  \
    struct _Checker {                                                                    \
      template <typename _Ty, _Rt (_Ty::*f)(_ARgs...) noexcept = &_Ty::methodName>       \
      static short check(int);                                                           \
      template <typename _Ty>                                                            \
      static char check(float);                                                          \
    };                                                                                   \
                                                                                         \
   public:                                                                               \
    const static bool value = sizeof(_Checker::template check<_Cl>(0)) == sizeof(short); \
  };                                                                                     \
  template <typename _Ty, typename _Rt = void, typename... _ARgs>                        \
  static constexpr bool inspectorName##_v = inspectorName<_Ty, _Rt, _ARgs...>::value  // EXISTENCE_NOEXCEPT_MEMBER_FUNCTION

// actually it is depends on cpp standard but msvc do not provide normal possibility to chek it in all projects
#if _MSC_VER > 1800
template <typename T, typename = void>
constexpr bool is_defined_v = false;

template <typename T>
constexpr bool is_defined_v<T, decltype(void(sizeof(T)))> = true;
#endif  //

}  // namespace types
}  // namespace aseed