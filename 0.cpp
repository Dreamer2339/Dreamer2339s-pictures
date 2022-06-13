#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll x,ll y){
	ll t=1;
	for(int i=1;i<=y;++i)t*=x;
	return t;
}
struct node{
	ll id,T;
	node(){
		id=0;
		T=1;
	}
	node(int _id,int _T){
		id=_id;
		T=_T;
	}
};
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
void exgcd(ll &x,ll &y,ll a,ll b,ll c){
	if(b==0){
		y=0;
		x=c/a;
		return;
	}
	exgcd(x,y,b,a%b,c);
	ll xx=-y,yy=-x-y*(a/b);
	x=xx;
	y=yy;
}
node merge(node x,node y){
	if(x.T==-1||y.T==-1||x.id==-1||y.id==1)return node(-1,-1);
	ll a=x.T,b=y.T,c=y.id-x.id,A,B,g=gcd(a,b);
	node res;
	if(c%g)return node(-1,-1);
	else{
		res.T=a/g*b;
		exgcd(A,B,a,b,c);
		res.id=((A*a+x.id)%res.T+res.T)%res.T;
		return res;
	}
}

//Fx mod pk == s,p=prime
node work(ll P,ll s,ll prime,ll pk){
	if(pk==prime){
		
	}
}
//Fx mod m == s
node solve(ll P,ll s,ll m){
	node res,tmp;
	int i;
	for(i=2;i<=23&&m>1;++i){
		if(m%i==0){
			ll t=1;
			while(m%i==0){
				m/=i;t*=i;
			}
			tmp=work(P,s%t,i,t);
			res=merge(tmp,res);
		}
	}
	return res;
}
int main(){
	int Q,T;
	scanf("%d",&T);
	ll P,m,s,k;
	node tmp;
	for(Q=1;Q<=T;++Q){
		scanf("%lld%lld%lld",&P,&m,&s);
		int s1=s;k=0;
		while(s1){
			s1/=10;
			++k;
		}
		tmp=solve(P,s,qpow(10LL,k));
		if(tmp.id==-1||tmp.T==-1){
			printf("Case #%d: -1\n",Q);
			continue;
		}
		tmp=solve(P,tmp.T,tmp.id);
		if(tmp.id==-1||tmp.T==-1){
			printf("Case #%d: -1\n",Q);
			continue;
		}
		k=max(0LL,(ll)ceil((m-tmp.id)/tmp.T));
		printf("Case #%d: %lld\n",Q,k*tmp.T+tmp.id);
	}
	return 0;
}