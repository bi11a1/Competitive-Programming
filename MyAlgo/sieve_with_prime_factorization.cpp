///Calculates primes up to MX
///smallest_pf[x] indicates smallest prime that divides x
///O(NlogN)
int smallest_pf[MX];
vector<int> primes;

void Sieve() { //O(n)
    for (int i = 2; i < MX; i++) {
        if (smallest_pf[i] == 0) {
            smallest_pf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > smallest_pf[i] || i * p >= MX) break;
            smallest_pf[i * p] = p;
        }
    }
}

void Sieve(){  //O(nlogn) with wrong smallest_pf[]
  int i, j;
  for(i=2; i<MX; ++i){
    if(smallest_pf[i]) continue;
    for(j=i; j<MX; j+=i) smallest_pf[j]=i;
  }
  for(i=2; i<MX; ++i){
    if(smallest_pf[i]==i) primes.push_back(i);
  }
}

///Returns prime_factors of number X as pairs of <prime, power>
///Requires to call sieve()
///O(NlogN)
vector<pair<int,int>> Factorize(int X){
  vector<pair<int,int>> factors;
  while(X>1){
    int base=smallest_pf[X], power=0;
    while(X%base==0){
      X/=base;
      power++;
    }
    factors.push_back({base, power});
  }
  return factors;
}
