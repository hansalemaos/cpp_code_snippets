#ifdef _WIN32
#include <windows.h>
#endif

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T> void print_type_traits(T myvar)
{
    std::cout << "has_unique_object_representations: " << (std::has_unique_object_representations<decltype(myvar)>())
              << '\n';
    std::cout << "has_virtual_destructor: " << (std::has_virtual_destructor<decltype(myvar)>()) << '\n';
    std::cout << "is_abstract: " << (std::is_abstract<decltype(myvar)>()) << '\n';
    std::cout << "is_aggregate: " << (std::is_aggregate<decltype(myvar)>()) << '\n';
    std::cout << "is_arithmetic: " << (std::is_arithmetic<decltype(myvar)>()) << '\n';
    std::cout << "is_array: " << (std::is_array<decltype(myvar)>()) << '\n';
    std::cout << "is_bounded_array: " << (std::is_bounded_array<decltype(myvar)>()) << '\n';
    std::cout << "is_class: " << (std::is_class<decltype(myvar)>()) << '\n';
    std::cout << "is_compound: " << (std::is_compound<decltype(myvar)>()) << '\n';
    std::cout << "is_const: " << (std::is_const<decltype(myvar)>()) << '\n';
    std::cout << "is_constructible: " << (std::is_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_copy_assignable: " << (std::is_copy_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_copy_constructible: " << (std::is_copy_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_default_constructible: " << (std::is_default_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_destructible: " << (std::is_destructible<decltype(myvar)>()) << '\n';
    std::cout << "is_empty: " << (std::is_empty<decltype(myvar)>()) << '\n';
    std::cout << "is_enum: " << (std::is_enum<decltype(myvar)>()) << '\n';
    std::cout << "is_final: " << (std::is_final<decltype(myvar)>()) << '\n';
    std::cout << "is_floating_point: " << (std::is_floating_point<decltype(myvar)>()) << '\n';
    std::cout << "is_function: " << (std::is_function<decltype(myvar)>()) << '\n';
    std::cout << "is_fundamental: " << (std::is_fundamental<decltype(myvar)>()) << '\n';
    std::cout << "is_integral: " << (std::is_integral<decltype(myvar)>()) << '\n';
    std::cout << "is_lvalue_reference: " << (std::is_lvalue_reference<decltype(myvar)>()) << '\n';
    std::cout << "is_member_function_pointer: " << (std::is_member_function_pointer<decltype(myvar)>()) << '\n';
    std::cout << "is_member_object_pointer: " << (std::is_member_object_pointer<decltype(myvar)>()) << '\n';
    std::cout << "is_member_pointer: " << (std::is_member_pointer<decltype(myvar)>()) << '\n';
    std::cout << "is_move_assignable: " << (std::is_move_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_move_constructible: " << (std::is_move_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_nothrow_copy_assignable: " << (std::is_nothrow_copy_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_nothrow_copy_constructible: " << (std::is_nothrow_copy_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_nothrow_move_assignable: " << (std::is_nothrow_move_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_nothrow_move_constructible: " << (std::is_nothrow_move_constructible<decltype(myvar)>()) << '\n';
    std::cout << "is_nothrow_swappable: " << (std::is_nothrow_swappable<decltype(myvar)>()) << '\n';
    std::cout << "is_null_pointer: " << (std::is_null_pointer<decltype(myvar)>()) << '\n';
    std::cout << "is_object: " << (std::is_object<decltype(myvar)>()) << '\n';
    std::cout << "is_pointer: " << (std::is_pointer<decltype(myvar)>()) << '\n';
    std::cout << "is_polymorphic: " << (std::is_polymorphic<decltype(myvar)>()) << '\n';
    std::cout << "is_reference: " << (std::is_reference<decltype(myvar)>()) << '\n';
    std::cout << "is_rvalue_reference: " << (std::is_rvalue_reference<decltype(myvar)>()) << '\n';
    std::cout << "is_scalar: " << (std::is_scalar<decltype(myvar)>()) << '\n';
    std::cout << "is_signed: " << (std::is_signed<decltype(myvar)>()) << '\n';
    std::cout << "is_standard_layout: " << (std::is_standard_layout<decltype(myvar)>()) << '\n';
    std::cout << "is_swappable: " << (std::is_swappable<decltype(myvar)>()) << '\n';
    std::cout << "is_trivial: " << (std::is_trivial<decltype(myvar)>()) << '\n';
    std::cout << "is_trivially_copy_assignable: " << (std::is_trivially_copy_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_trivially_copyable: " << (std::is_trivially_copyable<decltype(myvar)>()) << '\n';
    std::cout << "is_trivially_destructible: " << (std::is_trivially_destructible<decltype(myvar)>()) << '\n';
    std::cout << "is_trivially_move_assignable: " << (std::is_trivially_move_assignable<decltype(myvar)>()) << '\n';
    std::cout << "is_trivially_move_constructible: " << (std::is_trivially_move_constructible<decltype(myvar)>());
    std::cout << "is_unbounded_array: " << (std::is_unbounded_array<decltype(myvar)>()) << '\n';
    std::cout << "is_union: " << (std::is_union<decltype(myvar)>()) << '\n';
    std::cout << "is_unsigned: " << (std::is_unsigned<decltype(myvar)>()) << '\n';
    std::cout << "is_void: " << (std::is_void<decltype(myvar)>()) << '\n';
    std::cout << "is_volatile: " << (std::is_volatile<decltype(myvar)>()) << '\n';
}

int main()
{
    int32_t myvar = 0;
    print_type_traits(myvar);

    return 0;
}
