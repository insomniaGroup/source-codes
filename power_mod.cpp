//for taking Power_MOD.

    int POW_MOD(long base, int exp) {
        long result = 1;
        while (exp) {
            if (exp & 1) {
                result *= base;
                result %= MOD;
            }
            base *= base;
            base %= MOD;
            exp >>= 1;
        }
        return result;
    }
