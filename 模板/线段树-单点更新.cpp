int sp[10000],s[10000];
void update(int id,int l,int r,int x,int v)//¸üĞÂ
{
    if(l==r)
    {
        sp[id]+=v;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)
        update(id*2,l,m,x,v);
    else update(id*2+1,m+1,r,x,v);
    sp[id]=sp[id*2]+sp[id*2+1];
}
int query(int id,int l,int r,int ql,int qr)//²éÑ¯
{
    if(ql<=l&&r<=qr)
        return sp[id];
    int m=(l+r)/2;
    int ret=0;
    if(ql<=m)
        ret+=query(id*2,l,m,ql,qr);
    if(qr>m)
        ret+=query(id*2+1,m+1,r,ql,qr);
    return ret;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        cin>>s[p];
        return;
    }
    int m=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    sp[p]=sp[p*2]+sp[p*2+1];
}
