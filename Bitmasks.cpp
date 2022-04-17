// count number of ones in the binary representation of num
int Ones = __builtin_popcountll(num)


    
// ********************************************************************** //    
// To compute xor value from 0 to n
int compXOR(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

bool mnwr(int mask, int bit) {
    return ((mask >> bit) & 1);
}


