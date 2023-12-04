#include<stdio.h>
#include<string.h>
struct contactList{
	int id;
	char name[50];
	char phone[12];
	char address[50];
	int status;
	
};
typedef struct contactList cl;
void input (cl*temp){
	printf("id\n");
	scanf("%d",&temp->id);
	printf("ten\n");
	getchar();
	gets(temp->name);
	printf("so dien thoai\n");
	gets(temp->phone);
	printf("dia chi\n/");
	gets(temp->address);
	printf("trang thai\n");
	scanf("%d",&temp->status);
}
void output (cl*temp){
	printf("id: %d,ten: %s,so dien thoai: %s,dia chi: %s,trang thai: %d",temp->id,temp->name,temp->phone,temp->address,temp->status);
}
int main(){
	int n,i;
	int choice;
	int index =2;
	int count;
	cl contactList[2]=
	{
		{1,"Nguyen Nam Son ","031514874","Dong Anh",1},
		{2,"Le Dien Tien ","0332737489","Dong Anh",0}		
	};
	do{
		printf("1.In toan bo danh sach contact co trong mang tren cung 1 hang:\n");
		printf("2.Nhap them moi vao contact vao vi tri cuoi cung cua contactlist:\n");
		printf("3.Cap nhat tt contact neu ko tim thay in ra ko tim thay:\n");
		printf("4.x=Xoa 1 contact neu ko tim thay in ra ko tim thay:\n");
		printf("5.Thuc hien sap xep va in ra contact da duoc sap xep:\n");
		printf("6.Thuc hien tim kiem va in ra tt contact cung 1 hang:\n");
		printf("7.thuc hien tim kiem va in ra toan bo thong tin contact:");
		printf("\nMoi nhap lua chon:\n");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				 for (i=0;i<index;i++) {
                    printf("%d:",i+1);
                    output(&contactList[i]);
                    printf("\n");
                }
                break;
            case 2:
        		int add_Idcontact;
        		printf("nhap so lan them vao :");
        		scanf("%d",&add_Idcontact);
        		for (i=0;i<add_Idcontact;i++){
        		input(&contactList[index]);
        		index++;
			}
            	break;
            case 3:
            	 count=0;
            	int find_id;
                printf("nhap vao contact_id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == find_id)
                        {input(&contactList[i]);
						count =1;
						}
    			}
    			if(count==0){
    				printf("khong tim thay\n");
				}
                break;
            case 4 :
            	 count=0;
        	int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == delete_id)
                    for (int j=i;j<index-1;j++){
                      contactList[i] = contactList [i+1];	
                    	count=1;
					}
                }
                if(count==0){
    				printf("khong tim thay\n");
				}
                index--;
                break;
            case 6 :
            	count=0;
        	int find_contactId ;
        	printf("nhap contact_Id can tim :");
        	scanf("%d",&find_contactId);
			for (i=0;i<index;i++){
				if(contactList[i].id == find_contactId){
				output(&contactList[i]);
				count=1;		
				}
			}
			if(count==0){
    				printf("khong tim thay\n");
				}
		}
	}while(0); 
}
