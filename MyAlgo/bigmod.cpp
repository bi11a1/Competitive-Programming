  
ll BigMod(ll n_, ll p_, ll mod_){
  if(p_==0) return 1LL;
  if(p_&1LL) return (n_*BigMod(n_, p_-1LL, mod_))%mod_;
  ll tmp_=BigMod(n_, p_>>1LL, mod_);
  return (tmp_*tmp_)%mod_;
}

ll InverseMod(ll n_, ll mod_){ return BigMod(n_, mod_-2, mod_); }
