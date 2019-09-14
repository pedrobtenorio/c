char* read_tree()
{
  char c;
  char *s=(char*)malloc(500*sizeof(char));
  int op=0, cl=0, i=0;
  scanf("%c", &c);
  for(;;)
  {
    if(c != ' ' && c != '\n')
    {
      s[i++] = c;
    }
 
    if(c == '(')
      op++;
    else if(c==')')
      cl++;
 
    if(op==cl)
      break;
 
    scanf("%c", &c);
  }
  s[i] = '\0';
  return s;
}
 
binary_tree* construct_tree(char *s, int *i)
{
  binary_tree *bt=create_empty_tree();
  if(s[(*i)++] == '(')
  {
    if(s[*i] == ')')
    {
      (*i)++;
      return NULL;
    }
 
  char num[100];
  int j=0, x;
  while(s[*i] != '(')
  {
    num[j++] = s[(*i)++];
  }
 
  num[j]='\0';
  x=atoi(num);
 
  bt=create_binary_tree(x,NULL,NULL);
  bt->left=construct_tree(s,i);
  bt->right=construct_tree(s,i);
  }
  (*i)++;
  return bt;
}