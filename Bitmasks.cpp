// count number of ones in the binary representation of num
int onesCount = __builtin_popcountll(num);


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

int nwr(int mask, int bit) {
    return mask | (1LL << bit);
}

int dlm(int mask, int bit) {
    return mask & ~(1LL << bit);
}

int toggleBit(int mask, int bit) {
    return mask ^ (1LL << bit);
}

int leastSignificantBit(int mask) {
    return mask & (-mask);
}

int mostSignificantBit(int mask) {
    for (int i = 31; i >= 0; i--) {
        if (mnwr(mask, i)) {
            return (1LL << i);
        }
    }
    return 0;
}

bool isPowerOfTwo(int mask) {
    return !(mask & (mask - 1));
}

