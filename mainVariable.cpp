#include <gtest/gtest.h>
#include "utVariable.h"

//int main( int argc , char **argv )
int mainVariable( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
