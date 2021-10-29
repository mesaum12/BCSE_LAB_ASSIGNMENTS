int length(const char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}
int is_empty(const char *s)
{
    if(s[0]) return 0;
    return 1;
}
char* string_cat(char *s1,const char *s2)
{
    char *s=s1;
    while(*s)s++;
    while(*s++=*s2++);
    return s1;
}
int compare_str(const char *s1,const char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1<*s2)return -1;
        if(*s1>*s2) return 1;
        s1++;
        s2++;
    }
    if(*s1=='\0' && *s2=='\0')return 0;
    else if(*s1=='\0') return -1;
    return 1;
}
char* sub_str(const char *s,int beg,int len,char *destination)
{
   while(len>0)
   {
       *destination=*(s+beg);
       destination++;
       s++;
       len--;
   }
   *destination='\0';
   return destination;
   
}