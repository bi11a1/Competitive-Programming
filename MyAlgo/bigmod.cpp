ll big_mod(ll n_, ll p_, ll mod_){
     if(p_==0) return 1LL;
     if(p_&1LL) return (n_*big_mod(n_, p_-1LL, mod_))%mod_;
     ll tmp_=big_mod(n_, p_>>1LL, mod_);
     return (tmp_*tmp_)%mod;
}
ll inverse_mod(ll n_, ll mod_){ return big_mod(n_, mod_-2, mod_); }
