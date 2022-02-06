/*

Operation to be Perform in Edit Distance
1.) Insertion
2.)Deletion
3.)Replacement


and all operation cost :1


for example

cat --> cut --> 1 replacement

cast -->cat --->1 deletion (delete s from cast)

cats -->cast -->2 deletion(delete s from cats and insert s in cast)
                  insertion

   S1           S2
 sunday ---> saturday || find out number of operation to perform

 to convert s1 to s2
*/
 #include<bits/stdc++.h>
 using namespace std;
 #define inf INT_MAX

 //Basic Recursion
 int min (int x,int y,int z)
 {
   return min(min(x,y),z);
 }
 int EditDistance(char*in,char*output,int i,int j)
 {
   if(in==NULL||output==NULL)
   {
     return 0;
   }


   if(i==strlen(in))
   {
     return strlen(output)-j;
   }
   if(j==strlen(output))
   {
     return strlen(in)-i;
   }
   if(in[i]==output[j])
   {
     return EditDistance(in,output,i+1,j+1);

   }
  return 1+min(EditDistance(in,output,i+1,j+1),EditDistance(in,output,i+1,j),EditDistance(in,output,i,j+1));

 }
 //Memoization
//  int Edit_Distance(char*in,char*output,int i,int j,int memo[][100])
//  {
//    if(output==NULL || in==NULL)
//    {
//      return 0;
//    }
//    for(int i=0;i<=m)
//    if(i==strlen(in))
//    {
//      dp[i][j]=strlen(output)-j;
//    }
//    if(j==strlen(output))
//    {
//      dp[i][j]= strlen(in)-i;
//    }
//    if(in[i]==output[j])
//    {
//      dp[i][j]=dp[i+1][j+1]
//    }
//    if(memo[i][j]!=-1)
//    {
//      return memo[i][j];
//    }
// memo[i][j]=1+min(Edit_Distance(in,output,i+1,j+1,memo),Edit_Distance(in,output,i+1,j,memo),Edit_Distance(in,output,i,j+1,memo));
// int result=memo[s1][s2];
// return result;
//  }
int Edit_Distance(char *inp,char *out)
{
  int dp[101][101]={};
  int m=strlen(inp);
  int n=strlen(out);

  dp[0][0]=0;

  for(int i=1;i<=n;++i)
  dp[0][i]=dp[0][i-1]+1;//insertion (fill first row)
  
  for(int j=1;j<=m;j++)
  dp[j][0]=dp[j-1][0]+1; //deletion (fill first coloumn)
  
  for(int i=1;i<=m;++i)
  {
for(int j=1;j<=n;++j)
{
  int q1=dp[i-1][j-1]; //Replacement
  int q2=dp[i-1][j]; //deletion
  int q3=dp[i][j-1]; //insertion
  dp[i][j]=min(q1,min(q2,q3))+(inp[i-1]!=out[j-1]);  //this case when s1[i]=s2[j] when it is true means s1[i] not equal to s2[j] we add 1
  //else we add 0
}
  }
 return dp[m][n];

}
 int main(){
 char input[100];
 char output[100];
 cin>>input;
 cin>>output;
 int ans=EditDistance(input,output,0,0);
cout<<"Minimum  Edit Distance : "<<ans<<endl;

int memo[100][100]={};

int ans2=Edit_Distance(input,output);
cout<<"Minimum Edit Distance throw Dp : "<<ans2<<endl;
//
 return 0;
 }