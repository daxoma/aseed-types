#pragma once

namespace aseed {
namespace types {

// this works in msvc, clang, gcc

template <typename _Tag, size_t _Start = 0>
struct adl_scope {
  template <size_t _Nu>
  struct poly {
    friend constexpr bool flag(poly<_Nu>);
  };

  template <size_t _Nu>
  struct writer {
    friend constexpr bool flag(poly<_Nu>) { return true; }
    static constexpr size_t value = _Nu;
  };

  template <typename _Ty, size_t _Ix>
  static constexpr size_t index(float) noexcept {
    return writer<_Ix>::value;
  }

  template <typename _Ty, size_t _Ix, bool = flag(poly<_Ix>{})>
  static constexpr size_t index(int) noexcept {
    return index<_Ty, _Ix + 1>(0);
  }

  template <typename _Ty>
  static constexpr size_t index() noexcept {
    return index<_Ty, _Start>(0);
  }
};

/*
// it works in clang only, here i clearly use flag function in namespace and use friend specialization
template <typename _Ty>
constexpr bool flag(_Ty);

template <typename _Tag, size_t _Start = 0>
struct adl_scope {
  template <size_t _Nu>
  struct poly {};

  template <size_t _Nu>
  struct writer {
    friend constexpr bool flag<>(poly<_Nu>) { return true; }
    static constexpr size_t value = _Nu;
  };

  template <typename _Ty, size_t _Ix>
  static constexpr size_t index(float) noexcept {
    return writer<_Ix>::value;
  }

  template <typename _Ty, size_t _Ix, bool = flag(poly<_Ix>{})>
  static constexpr size_t index(int) noexcept {
    return index<_Ty, _Ix + 1>(0);
  }

  template <typename _Ty>
  static constexpr size_t index() noexcept {
    return index<_Ty, _Start>(0);
  }
};
*/

}  // namespace types
}  // namespace aseed