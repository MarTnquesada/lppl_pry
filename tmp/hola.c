{
    bool a[10];
    int i = 0;
    while( i < 10 ) {
        a[ i ] = true;
        i++;
    }
    a[5] = false;
    a[6] = false;
    i = 0;
    while( i < 10 ) {
        if( a[ i ] ) {
            print( 1 );
        }
        else {
            print( 0 );
        }
        i++;
    }
}