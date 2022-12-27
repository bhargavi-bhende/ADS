#include <iostream>
#include <queue>

using namespace std ;

struct pqcmpr
{
    bool operator () ( int a , int b )
    {
        return a > b ;    // > not < , because default is greater !
    }
} ;

int main ()
{
    int n , k ;
    cin >> n >> k ;
    priority_queue < int , vector < int > , pqcmpr > q ;    //  vector < int > is imp
    for ( int i = 0 ; i < n ; i ++ )
    {
        int no ;
        cin >> no ;
        q.push ( no ) ;
    }
    int counter = 0 ;
    if ( q.empty () == true )
    {
        counter = - 1 ;
    }
    else
    {
        while ( 1 )
        {
            int element1 = q.top () ;
            if ( element1 >= k )
            {
                break ;
            }
            q.pop () ;
            if ( q.empty () == true )
            {
                counter = - 1 ;
                break ;
            }
            int element2 = q.top () ;
            q.pop () ;
            q.push ( element1 + 2 * element2 ) ;
            counter ++ ;
        }
    }
    cout << counter ;
}
