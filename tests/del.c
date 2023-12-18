struct node* del( struct node *FIRST)
{
    struct node *T;
    if(( FIRST== NULL)&&(c<1))
    {
     printf("Underflow\n"); return FIRST;
    }
    T=top;
    printf("The deleted value is : %d\n",T->val);
    if(c!=1)
    {top=T->left;
    T->left= NULL; top->right=NULL;}
    else if(c==1)
    {FIRST=NULL;}
    c--;
    return FIRST;
}
