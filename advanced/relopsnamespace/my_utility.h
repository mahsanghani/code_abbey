//
// Created by Ahsan Ghani on 2022-08-23.
//
template< class T >
bool operator!=( const T& lhs, const T& rhs )
{
    return !(lhs == rhs);
}

template< class T >
bool operator>( const T& lhs, const T& rhs )
{
    return rhs < lhs;
}

template< class T >
bool operator<=( const T& lhs, const T& rhs )
{
    return !(rhs < lhs);
}

template< class T >
bool operator>=( const T& lhs, const T& rhs )
{
    return !(lhs < rhs);
}