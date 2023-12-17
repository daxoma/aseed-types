#pragma once

namespace aseed {
namespace types {

template <size_t... Seq>
struct sequence {};

template <size_t Pos, size_t N, size_t... Seq>
struct make_sequence {
  using type = typename make_sequence<Pos + 1, N, Seq..., Pos>::type;
};

template <size_t N, size_t... Seq>
struct make_sequence<N, N, Seq...> {
  using type = sequence<Seq...>;
};

template <size_t Pos, size_t N>
using make_sequence_t = typename make_sequence<Pos, N>::type;

}  // namespace types
}  // namespace aseed