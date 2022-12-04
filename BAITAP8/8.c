#include <stdio.h>
#include <math.h>
// Mảng lưu vị trí đặt Queen. Tối đa đặt 20 queen trên bàn cờ 20x20
//Tham số bàn cờ tính từ 1..n
int solution[20];
int count=0; //số phương án chấp nhận được
FILE*file_target; //file kết quả
//Kiểm tra cách đặt có thỏa mãn không
//x2,y2: vị trí đặt queen ở cột mới
int OK(int x2,int y2)
{
    //So sánh với các vị trí đã đặt Queen lúc trước
    for(int i = 1; i < x2; i++)
        if(solution[i] == y2 || abs(i-x2) == abs(solution[i] - y2) )
            return 0;
    //Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
    return 1;
}

//Hàm in ra kết một kết quả
void Xuat(int n)
{
    count++;
    //In ra màn hình
    printf("PA %d\n",count);
    for(int col=1;col<=n;col++)
        printf(" %d",solution[col]);
    printf("\n");
    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=n;col++)
        {
            if(solution[col]==row)  printf(" Q");
            else printf(" -");
        }
        printf("\n");
    }
    printf("-------------------\n");
    //in vào file
    fprintf(file_target,"PA %d\n",count);
    for (int col=1;col<=n;col++)
        fprintf(file_target," %d",solution[col]);
    fprintf(file_target,"\n");
    for(int row=1;row<=n;row++)
    {
        for(int col=1;col<=n;col++)
        {
            if(solution[col]==row)  fprintf(file_target," Q");
            else fprintf(file_target," -");
        }
        fprintf(file_target,"\n");
    }
    fprintf(file_target,"------------------- \n");
}

//Hàm thử một phương án đặt quân hậu
void Try(int i,int n){
    for(int j=1;j<=n;j++){
        //thử đặt quân hậu vào các cột từ 1 đến n
        if(OK(i,j)){
                //nếu cách đặt này thỏa mãn thì lưu lại vị trí
            solution[i] = j;
            //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }

}

int main()
{
    int n = 8;//bài toán là 8 quân hậu trên bàn 8*8
    file_target=fopen("output_Cau8.txt","w");
    Try(1,n);
    fclose(file_target);
    return 0;
}