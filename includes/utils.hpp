//
// Created by Stephane Walter on 1/9/23.
//

#ifndef FT_CONTENAIR_UTILS_HPP
#define FT_CONTENAIR_UTILS_HPP



namespace ft{
/* -------------------------------------------------------------------------- */
/*                                    equal                                   */
/* -------------------------------------------------------------------------- */

    template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2){
        for(; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2))
                return false;
        }
        return true;
    }

    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p ){
        for(; first1 != last1; ++first1, ++first2){
            if (!(p(*first1 == *first2)))
                return false;
        }
        return true;
    }


/* -------------------------------------------------------------------------- */
/*                  lexicographical_compare                                   */
/* -------------------------------------------------------------------------- */


    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
        for(; (first1 != last1) && (first2 != last2); ++first1, (void)++first2){
            if(*first2 < *first1)
                return false;
            if(*first1 < *first2)
                return true;
        }
        return (first1 == last1 ) && (first2 != last2);
    }



    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp){
        for(; (first1 != last1) && (first2 != last2); ++first1, (void)++first2){
            if(comp(*first1, *first2))
                return true;
            if(comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }



/* -------------------------------------------------------------------------- */
/*                                  enable if                                 */
/* -------------------------------------------------------------------------- */
    template<bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T>{
        typedef T type;
    };


/* -------------------------------------------------------------------------- */
/*                                 is integral                                */
/* -------------------------------------------------------------------------- */

    template<class T> struct is_integral {static const bool value = false; };
    template <> struct is_integral<bool> {static const bool value = true;};
    template <> struct is_integral<char> {static const bool value = true;};
    template <> struct is_integral<unsigned char> {static const bool value = true;};
    template <> struct is_integral<signed char> {static const bool value = true;};
    template <> struct is_integral<wchar_t> {static const bool value = true;};
    template <> struct is_integral<short> {static const bool value = true;};
    template <> struct is_integral<unsigned short> {static const bool value = true;};
    template <> struct is_integral<int> {static const bool value = true;};
    template <> struct is_integral<unsigned int> {static const bool value = true;};
    template <> struct is_integral<long> {static const bool value = true;};
    template <> struct is_integral<unsigned long> {static const bool value = true;};
    template <> struct is_integral<long long> {static const bool value = true;};
    template <> struct is_integral<unsigned long long> {static const bool value = true;};
    template <> struct is_integral<__int128_t> {static const bool value = true;};
    template <> struct is_integral<__uint128_t> {static const bool value = true;};



}

#endif //FT_CONTENAIR_UTILS_HPP