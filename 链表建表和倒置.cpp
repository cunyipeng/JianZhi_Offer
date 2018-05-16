struct ListNode  
{  
  int val;  
  ListNode *next;  
};  

ListNode* Creat_List(int a[],int n)  
{  
 ListNode* p=new ListNode();  
 p->val=a[0];  
 p->next=NULL;  
 ListNode* head=p;  
  for(int i=1;i<n;i++)  
  {  
    ListNode* tem=new ListNode();  
    tem->val=a[i];  
    tem->next=NULL;  
      
    p->next=tem;  
    p=tem;  
  }  
  p->next=NULL;  
  return head;  
}  

ListNode* ReverseList(ListNode* head)  
{  
  ListNode *newhead=NULL;  
  ListNode *node=head;  
  ListNode *pre=NULL;  
  while(node!=NULL)  
  {  
   ListNode *nextnode=node->next;  
   if(nextnode==NULL)  
       newhead=node;//注意！！！此时不返回头结点。     
    node->next=pre;  
    pre=node;  
    node=nextnode;  
  }  
  return newhead;  
}  
  
ListNode* ReverseList2(ListNode* head)  
{  
  if(head==NULL||head->next==NULL)  
      return head;  
  ListNode* newhead=ReverseList2(head->next);  
  head->next->next=head;  
  head->next=NULL;  
  return newhead;  
}  
  
int main()  
{  
   int a[9]={9,8,7,6,5,4,3,2,1};  
   ListNode *head=Creat_List(a,9);  
   ListNode *newhead=ReverseList(head);  
   while(newhead!=NULL)  
   {  
     cout<<newhead->val;  
     newhead=newhead->next;  
   }  
   cout<<endl;  
   return 0;  
}  
