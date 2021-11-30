//---------------------------------------------------------------------------

#include <vcl.h>
#include "jpeg.hpp"
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// 開檔
void __fastcall TForm1::Open1Click(TObject *Sender)
{
  if(BMP->Checked == true) // 選擇BMP格式
  {
    Graphics::TBitmap *Bmp = new Graphics::TBitmap(); // 新增圖像檔(格式為BMP)
    if(OpenPictureDialog1->Execute()) // 物件(OpenPictureDialog1)執行時
    {
      Bmp->LoadFromFile(OpenPictureDialog1->FileName);
        // 載入OpenPictureDialog1所開啟的檔案到Bmp
      Image1->Width = Bmp->Width; // 將Image1的寬設成讀入影像的寬
      Image1->Height = Bmp->Height; // 將Image1的高設成讀入影像的高
      Image1->Picture->Bitmap = Bmp;
    }
    delete Bmp;
  }
// include jpeg檔案(#include "jpeg.hpp")
  if(JPEG->Checked == true) // 選擇JPEG格式
  {
    TJPEGImage *JImage = new TJPEGImage;// 新增圖像檔(格式為JPEG)
    if(OpenPictureDialog1->Execute()) // 物件(OpenPictureDialog1)執行時
    {
      JImage->LoadFromFile(OpenPictureDialog1->FileName);
        // 載入OpenPictureDialog1所開啟的檔案到JImage
      Image1->Width = JImage->Width;
      Image1->Height = JImage->Height;
      Image1->Picture->Bitmap->Assign(JImage);
    }
    delete JImage;
  }
   if(BMP->Checked != true && JPEG->Checked != true){
    ShowMessage("請選擇圖檔格式");
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Close1Click(TObject *Sender)
{   // 關閉程式
  Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{   // 滑鼠移動事件
  unsigned char R, G, B;
  if(Image1->Picture->Bitmap->Empty!=true)
  {
    StatusBar1->Panels->Items[0]->Text = "X : " + IntToStr(X + 1);
    StatusBar1->Panels->Items[1]->Text = "Y : " + IntToStr(Y + 1);
    R = GetRValue(Image1->Canvas->Pixels[X][Y]);
    G = GetGValue(Image1->Canvas->Pixels[X][Y]);
    B = GetBValue(Image1->Canvas->Pixels[X][Y]);
    StatusBar1->Panels->Items[2]->Text = " R : " + IntToStr(R) + "  G : " + IntToStr(G) + "  B : " + IntToStr(B);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{  // 滑鼠點擊事件
  unsigned char R, G, B;
  if(Image1->Picture->Bitmap->Empty!=true)
  {
    R = GetRValue(Image5->Canvas->Pixels[X][Y]);
    G = GetGValue(Image5->Canvas->Pixels[X][Y]);
    B = GetBValue(Image5->Canvas->Pixels[X][Y]);
    StatusBar1->Panels->Items[3]->Text ="X : "+IntToStr(X + 1)+"  Y : "+IntToStr(Y + 1)+
      "     R : "+IntToStr(R)+"   G : " + IntToStr(G)+"   B : "+IntToStr(B);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{ // 存檔
  if(JPEG->Checked == true){ // 原檔為JPEG格式 存為JPEG格式
    if(Image2->Picture->Bitmap->Empty!=true){
      SavePictureDialog1->Execute();
      Image2->Picture->SaveToFile(SavePictureDialog1->FileName+"(2).jpeg");
    }
    if(Image3->Picture->Bitmap->Empty!=true){
      Image3->Picture->SaveToFile(SavePictureDialog1->FileName+"(3).jpeg");
    }
    if(Image4->Picture->Bitmap->Empty!=true){
      Image4->Picture->SaveToFile(SavePictureDialog1->FileName+"(4).jpeg");
    }
  }

  if(BMP->Checked == true){ // 原檔為BMP格式 存為BMP格式
    if(Image2->Picture->Bitmap->Empty!=true){
      SavePictureDialog1->Execute();
      Image2->Picture->SaveToFile(SavePictureDialog1->FileName+"(2).bmp");
    }
    if(Image3->Picture->Bitmap->Empty!=true){
      Image3->Picture->SaveToFile(SavePictureDialog1->FileName+"(3).bmp");
    }
    if(Image4->Picture->Bitmap->Empty!=true){
      Image4->Picture->SaveToFile(SavePictureDialog1->FileName+"(4).bmp");
    }
  }
  ShowMessage("完成存檔");
}
//---------------------------------------------------------------------------

void histogram(int image_h, int image_w){
    Form1->Chart1->Legend->Visible = false; // 關閉圖例
    Form1->Chart1->View3D=false; // 不要 3D 立體
    Form1->Chart1->Title->Text->Clear();
    Form1->Chart1->Title->Text->Add("histogram"); // 設定標題
    Form1->Chart1->LeftAxis->Automatic = false; //
    Form1->Chart1->LeftAxis->AutomaticMinimum = false;
    Form1->Chart1->LeftAxis->AutomaticMaximum = true;
    Form1->Chart1->LeftAxis->Minimum=0; // 設定 從0開始
    Form1->Chart1->BottomAxis->Automatic = false;
    Form1->Chart1->BottomAxis->AutomaticMinimum = false;
    Form1->Chart1->BottomAxis->AutomaticMaximum = false;
    Form1->Chart1->BottomAxis->Maximum = 255; // 最大到255
    Form1->Chart1->BottomAxis->Minimum = 0;
    unsigned char graylevel_val[256]={0}, R;
    for(int i = 0; i < image_h; i++){
      for(int j = 0; j < image_w; j++){
        R = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        graylevel_val[R]++;
      }
    }
    for(int k =0; k < 256; k++){ Form1->Series1->Add(graylevel_val[k], "");}
}

void __fastcall TForm1::N3Click(TObject *Sender)
{ // 灰階(需按工具列)
  if(Image1->Picture->Bitmap->Empty!=true){ // 判斷是否有開檔
    unsigned char R, G, B;
    int image1_w = 0, image1_h = 0;  // image1的寬跟高(控制迴圈)
    Image2->Width = Image1->Width;  // 設定image2寬跟高
    Image5->Width = Image1->Width;
    Image2->Height = Image1->Height;
    Image5->Height = Image1->Height;
    image1_w = Image1->Width;
    image1_h = Image1->Height;
    for(int i = 0; i < image1_h; i++){
      for(int j = 0; j < image1_w; j++){
        R = GetRValue(Form1->Image1->Canvas->Pixels[i][j]);
        G = GetGValue(Form1->Image1->Canvas->Pixels[i][j]);
        B = GetBValue(Form1->Image1->Canvas->Pixels[i][j]);
        Form1->Image2->Canvas->Pixels[i][j]=(TColor)RGB((R+G+B)/3,(R+G+B)/3,(R+G+B)/3);
        Form1->Image5->Canvas->Pixels[i][j]=(TColor)RGB((R+G+B)/3,(R+G+B)/3,(R+G+B)/3);
      }
    }
    histogram(image1_h, image1_w);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N1Click(TObject *Sender)
{ // 灰階縮小圖檔(假設圖都為n^x)

}
//---------------------------------------------------------------------------

bool aa=false;
void __fastcall TForm1::N4Click(TObject *Sender)
{  // 灰階縮小圖檔(4點相加算平均)
  if(aa==false){
    int image_w = 0, image_h = 0, sum = 0;
    image_w = Image2->Width;   image_h = Image2->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        sum = GetRValue(Form1->Image2->Canvas->Pixels[i][j])
          + GetRValue(Form1->Image2->Canvas->Pixels[i][j+1])
          + GetRValue(Form1->Image2->Canvas->Pixels[i+1][j])
          + GetRValue(Form1->Image2->Canvas->Pixels[i+1][j+1]);
         sum=sum/4;
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(sum, sum, sum);
      }
    } aa=true;
  }
  else{
    int image_w = 0, image_h = 0, sum = 0;
    image_w = Image3->Width;   image_h = Image3->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        sum = GetRValue(Form1->Image3->Canvas->Pixels[i][j])
          + GetRValue(Form1->Image3->Canvas->Pixels[i][j+1])
          + GetRValue(Form1->Image3->Canvas->Pixels[i+1][j])
          + GetRValue(Form1->Image3->Canvas->Pixels[i+1][j+1]);
         sum=sum/4;
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(sum, sum, sum);
      }
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{  // 灰階縮小圖檔(4點取最大值)
  if(aa==false){
    int image_w = 0, image_h = 0, image_gray[3], max;
    image_w = Image2->Width;   image_h = Image2->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        max = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        image_gray[0] = GetRValue(Form1->Image2->Canvas->Pixels[i][j+1]);
        image_gray[1] = GetRValue(Form1->Image2->Canvas->Pixels[i+1][j]);
        image_gray[2] = GetRValue(Form1->Image2->Canvas->Pixels[i+1][j+1]);
        for(int count = 0; count < 3; count++){
          if(image_gray[count] > max){max = image_gray[count];}
        }
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(max, max, max);
      }
    }aa=true;
  }
  else{
    int image_w = 0, image_h = 0, image_gray[3], max;
    image_w = Image3->Width;   image_h = Image3->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        max = GetRValue(Form1->Image3->Canvas->Pixels[i][j]);
        image_gray[0] = GetRValue(Form1->Image3->Canvas->Pixels[i][j+1]);
        image_gray[1] = GetRValue(Form1->Image3->Canvas->Pixels[i+1][j]);
        image_gray[2] = GetRValue(Form1->Image3->Canvas->Pixels[i+1][j+1]);
        for(int count = 0; count < 3; count++){
          if(image_gray[count] > max){max = image_gray[count];}
        }
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(max, max, max);
      }
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N6Click(TObject *Sender)
{  // 灰階縮小圖檔(4點取最小值)
  if(aa==false){ // 判斷是否有灰階圖
    int image_w = 0, image_h = 0, image_gray[3], min;
    image_w = Image2->Width;   image_h = Image2->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        min = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        image_gray[0] = GetRValue(Form1->Image2->Canvas->Pixels[i][j+1]);
        image_gray[1] = GetRValue(Form1->Image2->Canvas->Pixels[i+1][j]);
        image_gray[2] = GetRValue(Form1->Image2->Canvas->Pixels[i+1][j+1]);
        for(int count = 0; count < 3; count++){
          if(image_gray[count] < min){min = image_gray[count];}
        }
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(min, min, min);
      }
    }aa=true;
  }
  else{
    int image_w = 0, image_h = 0, image_gray[3], min;
    image_w = Image3->Width;   image_h = Image3->Height;
    Image3->Width = image_w/2;   Image3->Height = image_h/2;
    for(int i = 0; i < image_h; i+=2){
      for(int j = 0; j < image_w; j+=2){
        min = GetRValue(Form1->Image3->Canvas->Pixels[i][j]);
        image_gray[0] = GetRValue(Form1->Image3->Canvas->Pixels[i][j+1]);
        image_gray[1] = GetRValue(Form1->Image3->Canvas->Pixels[i+1][j]);
        image_gray[2] = GetRValue(Form1->Image3->Canvas->Pixels[i+1][j+1]);
        for(int count = 0; count < 3; count++){
          if(image_gray[count] < min){min = image_gray[count];}
        }
        Form1->Image3->Canvas->Pixels[i/2][j/2]=(TColor)RGB(min, min, min);
      }
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{ //  馬賽克(灰階) 用val*val的大小
  if(Image2->Picture->Bitmap->Empty!=true){ // 判斷是否有灰階圖
    int image_w = 0, image_h = 0, val = 0, image_val = 0;
    unsigned char R;
    val = StrToInt(Edit2->Text);
    image_w = Image2->Width;   image_h = Image2->Height;
    Image4->Width = image_w;   Image4->Height = image_h;
    for(int i = 0; i < image_h; i+=val){
      for(int j = 0; j < image_w; j+=val){
        image_val = GetRValue(Form1->Image2->Canvas->Pixels[i][j]); // 用左上角的值
        for(int q = 0; q < val; q++){
          for(int k = 0; k < val; k++){
            //Form1->Image4->Canvas->Pixels[i+q][j+k]=(TColor)RGB(image_val, image_val, image_val);
            image_val+= GetRValue(Form1->Image2->Canvas->Pixels[i+q][j+k]);
          }
        }
        R=image_val/((val*val)+1);
        for(int q = 0; q < val; q++){
          for(int k = 0; k < val; k++){
            Form1->Image4->Canvas->Pixels[i+q][j+k]=(TColor)RGB(R, R, R);
          }
        }
      }
    }
  }
}
//---------------------------------------------------------------------------

void fun(int image_w, int image_h, int val){
  unsigned char R;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
      for(int k = 0; k < val; k++){R = (int)(R/2);}
      Form1->Image5->Canvas->Pixels[i][j]=(TColor)RGB(R, R, R);
    }
  }
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      for(int k = 0; k < val; k++){R *= 2;}
      if(val==7){if(R!=0){R =255;}}
      Form1->Image5->Canvas->Pixels[i][j]=(TColor)RGB(R, R, R);
    }
  }
}

void __fastcall TForm1::N2561281Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 1);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N128641Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 2);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N64321Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 3);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N32161Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 4);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1681Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 5);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N841Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 6);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){ Series1->Add(graylevel_val[k], k, clBlue);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N421Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image5->Width = image_w;   Image5->Height = image_h;
  fun(image_w, image_h, 7);
  unsigned char graylevel_val[256]={0}, R;
  Series1->Clear();
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image5->Canvas->Pixels[i][j]);
      graylevel_val[R]++;
    }
  }
  for(int k =0; k < 256; k++){Series1->Add(graylevel_val[k], k, clBlue);}
}
  // 降色階
//---------------------------------------------------------------------------

void __fastcall TForm1::N7_1Click(TObject *Sender)
{
  int image_w = 0, image_h = 0, val = 0, image_val = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image6->Width = image_w;   Image6->Height = image_h;
  if(Edit3->Text == ""){val = 3;}
  else{val = StrToInt(Edit3->Text);}
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
          image_val+= GetRValue(Form1->Image2->Canvas->Pixels[i+q][j+k]);
        }
      }
      image_val = image_val/(val * val);
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
           Form1->Image6->Canvas->Pixels[i+q][j+k]=(TColor)RGB(image_val, image_val, image_val);
        }
      }
    }
  }
}

//---------------------------------------------------------------------------

void quicksort(int a[], int left, int right){  // quick sort
  if (left >= right) return;
  int i = left, j = right;
  int  key = a[i],tmp;
  while (1) {
    while (a[j] > key) j--;
    while (a[i] < key) i++;
    if(i >= j) break;
    tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    i++;j--;
  }
    if(left  < i - 1)   quicksort(a, left, i - 1);
    if(j + 1 < right)  quicksort(a, j + 1 , right);
}
void __fastcall TForm1::N7_2Click(TObject *Sender)
{
  int image_w = 0, image_h = 0, val = 0, image_val = 0, *a, apoint;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image6->Width = image_w;   Image6->Height = image_h;
  if(Edit3->Text == ""){val = 3;}
  else{val = StrToInt(Edit3->Text);}
  a = new int[(val * val)];
  Label3->Caption = IntToStr(val);
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      apoint = 0;
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
          a[apoint++]= GetRValue(Form1->Image2->Canvas->Pixels[i+q][j+k]);
        }
      }
      quicksort(a, 0,(val * val)-1);
      image_val = a[val/2];
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
          Form1->Image6->Canvas->Pixels[i+q][j+k]=(TColor)RGB(image_val, image_val, image_val);
        }
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Laplacian1Click(TObject *Sender)
{
  int image_w = 0, image_h = 0, image_val = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image7->Width = image_w;   Image7->Height = image_h;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      if(i < 1 || j < 1 || i > image_h - 3 || j > image_w - 3){
        image_val = 255;
        Form1->Image7->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
      else{
        image_val = 4 * GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i+1][j]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i][j+1]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i][j-1]));
        image_val = abs(image_val);
        Form1->Image7->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Sobel1Click(TObject *Sender)
{
  int image_w = 0, image_h = 0, image_val = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image7->Width = image_w;   Image7->Height = image_h;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      if(i < 1 || j < 1 || i > image_h - 3 || j > image_w - 3){
        image_val = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        Form1->Image7->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
      else{
        int image_row = 0, image_col = 0;
        image_row += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j-1]));
        image_row += (-2 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j]));
        image_row += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j+1]));
        image_row += GetRValue(Form1->Image2->Canvas->Pixels[i+1][j-1]);
        image_row += (2 * GetRValue(Form1->Image2->Canvas->Pixels[i+1][j]));
        image_row += GetRValue(Form1->Image2->Canvas->Pixels[i+1][j+1]);

        image_col += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j-1]));
        image_col += (-2 * GetRValue(Form1->Image2->Canvas->Pixels[i][j-1]));
        image_col += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i+1][j-1]));
        image_col += GetRValue(Form1->Image2->Canvas->Pixels[i-1][j+1]);
        image_col += (2 * GetRValue(Form1->Image2->Canvas->Pixels[i][j+1]));
        image_col += GetRValue(Form1->Image2->Canvas->Pixels[i+1][j+1]);
        image_row = abs(image_row);
        image_col = abs(image_col);
        if(image_row > image_col){image_val = image_row;}
        else {image_val = image_col;}
        Form1->Image7->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Laplacian2Click(TObject *Sender)
{
  int image_w = 0, image_h = 0, image_val = 0;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image8->Width = image_w;   Image8->Height = image_h;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      if(i < 1 || j < 1 || i > image_h - 3 || j > image_w - 3){
        image_val = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        Form1->Image8->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
      else{
        image_val = 5 * GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i-1][j]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i+1][j]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i][j+1]));
        image_val += (-1 * GetRValue(Form1->Image2->Canvas->Pixels[i][j-1]));
        image_val = abs(image_val);
        if(image_val > 255){image_val = 255;}
        Form1->Image8->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{  // 模糊化(最大)
  int image_w = 0, image_h = 0, val = 0, image_val = 0, *a, apoint;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image6->Width = image_w;   Image6->Height = image_h;
  if(Edit3->Text == ""){val = 3;}
  else{val = StrToInt(Edit3->Text);}
  a = new int[(val * val)];
  Label3->Caption = IntToStr(val);
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      if(i < 1 || j < 1 || i > image_h - 3 || j > image_w - 3){
        image_val = GetRValue(Form1->Image2->Canvas->Pixels[i][j]);
        Form1->Image6->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);
      }
      else{
        image_val = 0;
        apoint = 0;
        for(int q = -1; q < val-1; q++){
          for(int k = -1; k < val-1; k++){
            a[apoint++]= GetRValue(Form1->Image2->Canvas->Pixels[i+q][j+k]);
          }
        }
        quicksort(a, 0,(val * val)-1);
        image_val = a[0];
        for(int q = 0; q < val; q++){
          for(int k = 0; k < val; k++){
        Form1->Image6->Canvas->Pixels[i][j]=(TColor)RGB(image_val, image_val, image_val);}}
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{  // 模糊化(最小)
  int image_w = 0, image_h = 0, val = 0, image_val = 0, *a, apoint;
  image_w = Image2->Width;   image_h = Image2->Height;
  Image6->Width = image_w;   Image6->Height = image_h;
  if(Edit3->Text == ""){val = 3;}
  else{val = StrToInt(Edit3->Text);}
  a = new int[(val * val)];
  Label3->Caption = IntToStr(val);
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      image_val = 0;
      apoint = 0;
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
          a[apoint++]= GetRValue(Form1->Image2->Canvas->Pixels[i+q][j+k]);
        }
      }
      quicksort(a, 0,(val * val)-1);
      image_val = a[val];
      for(int q = 0; q < val; q++){
        for(int k = 0; k < val; k++){
          Form1->Image6->Canvas->Pixels[i+q][j+k]=(TColor)RGB(image_val, image_val, image_val);
        }
      }
    }
  }
}
//---------------------------------------------------------------------------
double Real[150][150], Imaginary[150][150];
void __fastcall TForm1::DFT1Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  int u, v, x, y; // 控制迴圈
  double real = 0, imaginary = 0;
  image_w = Image1->Width;   image_h = Image1->Height;
  Image10->Width = image_w;   Image10->Height = image_h;

  for(u = 0; u < image_h; u++){
    for(v = 0; v < image_w; v++){
      for(x = 0; x < image_h; x++){
        for(y = 0; y < image_w; y++){
          int p = pow(-1,(double)x + y);
          int g = GetRValue(Image2 -> Canvas -> Pixels[x][y]);
          real += g * cos((double)2 * M_PI  * (u * x  + v * y) / Image1 -> Width) * p;
          imaginary += g * sin((double)2 * M_PI  * (u * x  + v * y) / Image1 -> Width) * p;
        }
      }
      real = real / (Image2 -> Width);
      imaginary = imaginary / (Image2 -> Width);
      Real[u][v] = real;
      Imaginary[u][v] = imaginary;
      int f = sqrt((real*real)+(imaginary*imaginary));
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Form1->Image10->Canvas->Pixels[u][v]=(TColor)RGB(f, f, f);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IDFT1Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  int u, v, x, y; // 控制迴圈
  image_w = Image1->Width;   image_h = Image1->Height;
  Image9->Width = image_w;   Image9->Height = image_h;

  for(u = 0; u < image_h; u++){
    for(v = 0; v < image_w; v++){
      double real = 0, imaginary = 0;
      for(x = 0; x < image_h; x++){
        for(y = 0; y < image_w; y++){
          double a = 2 * M_PI * (u * x + v * y) / Image1 -> Width;
          real += Real[x][y] * cos(a) - Imaginary[x][y] * sin(a);
          imaginary += Imaginary[x][y] * cos(a) + Real[x][y] * sin(a);
        }
      }
      real = real / Image1 -> Width;
      imaginary = imaginary / Image1 -> Width;
      int f = sqrt(real * real + imaginary * imaginary);
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Image9->Canvas->Pixels[u][v] = (TColor) RGB( f,  f,  f);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  int image_w = 0, image_h = 0;
  int u, v, x, y; // 控制迴圈
  double real = 0, imaginary = 0;
  image_w = Image1->Width;   image_h = Image1->Height;
  Image10->Width = image_w;   Image10->Height = image_h;

  for(u = 0; u < image_h; u++){
    for(v = 0; v < image_w; v++){
      for(x = 0; x < image_h; x++){
        for(y = 0; y < image_w; y++){
          int p = pow(-1,(double)x + y);
          int g = GetRValue(Image2 -> Canvas -> Pixels[x][y]);
          real += g * cos((double)2 * M_PI  * (u * x  + v * y) / Image1 -> Width) * p;
          imaginary += g * sin((double)2 * M_PI  * (u * x  + v * y) / Image1 -> Width) * p;
        }
      }
      real = real / (Image2 -> Width);
      imaginary = imaginary / (Image2 -> Width);
      Real[u][v] = real;
      Imaginary[u][v] = imaginary;
      int f = sqrt((real*real)+(imaginary*imaginary));
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Form1->Image10->Canvas->Pixels[u][v]=(TColor)RGB(f, f, f);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{         // Real[150][150], Imaginary[150][150];
  double M = Image2->Picture->Bitmap->Width;
  double N = Image2->Picture->Bitmap->Height;
  int u, v, x, y, d, d1=10, n = 2;
  double real, image, da;
  double h[150][150], R1[150][150], I1[150][150];

  Image11 -> Width = Image2 -> Width;
  Image11 -> Height = Image2 -> Height;
  Image11 -> Picture ->Bitmap -> Height = M;
  Image11 -> Picture ->Bitmap -> Width = N;

  if(RadioButton3 -> Checked == True){      //ideal
    for(int u = 0;u < M;u++){
      for(int v = 0;v < N;v++){
        d = sqrt(pow(u - M / 2,2) + pow(v - N / 2,2));
          if(d <= d1)h[u][v] = 1;
          else h[u][v]=0;
        }
      }
    }

    if(RadioButton4 -> Checked == True){       //butterworth
      for(int u = 0;u < M;u++){
        for(int v = 0;v < N;v++){
          d = sqrt(pow(u - M / 2,2) + pow(v - N / 2,2));
          h[u][v] = 1 / (1 + pow(d / d1,2 * n));
        }
      }
    }
    for(int u = 0;u < M;u++){
      for(int v = 0;v < N;v++){
        R1[u][v] = Real[u][v] * h[u][v] ;
        I1[u][v] = Imaginary[u][v] * h[u][v] ;
      }
    }
    for(u = 0; u < M; u++){
    for(v = 0; v < N; v++){
      double real = 0, imaginary = 0;
      for(x = 0; x < M; x++){
        for(y = 0; y < N; y++){
          double a = -2 * M_PI * (u * x + v * y) / N;
          real += R1[x][y] * cos(a) - I1[x][y] * sin(a);
          imaginary += I1[x][y] * cos(a) + R1[x][y] * sin(a);
        }
      }
      real = real / M;
      imaginary = imaginary / M;
      int f = sqrt(real * real + imaginary * imaginary);
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Image11->Canvas->Pixels[u][v] = (TColor) RGB( f,  f,  f);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  double M = Image2 -> Picture -> Bitmap -> Width;
  double N = Image2 -> Picture -> Bitmap -> Height;
  int u, v, x, y, d, d1 = 11, n = 2;
  double real, image, da;
  double h[150][150], R1[150][150], I1[150][150];

  Image12 -> Width = Image2 -> Width;
  Image12 -> Height = Image2 -> Height;
  Image12 -> Picture -> Bitmap -> Height = Image2 -> Picture -> Bitmap -> Height;
  Image12 -> Picture -> Bitmap -> Width = Image2 -> Picture -> Bitmap -> Width;

  if(RadioButton3 -> Checked == True){
    for(int u = 0;u < M;u++){
      for(int v = 0;v < N;v++){
        d = sqrt(pow(u - M / 2,2) + pow(v - N / 2,2));
          if(d <= d1)h[u][v] = 0;
          else{h[u][v] = 1;}
        }
      }
    }
    if(RadioButton4 -> Checked == True){
      for(int u = 0;u < M;u++){
        for(int v = 0;v < N;v++){
          d = sqrt(pow(u - M / 2,2) + pow(v - N / 2,2));
            if(d == 0) d = 1;
            h[u][v] = 1 / (1 + pow(d1 / d,2 * n));
          }
        }
      }
    for(int u = 0;u < M;u++){
      for(int v = 0;v < N;v++){
        R1[u][v] = Real[u][v] * h[u][v] ;
        I1[u][v] = Imaginary[u][v] * h[u][v] ;
      }
    }
    for(u = 0; u < M; u++){
    for(v = 0; v < N; v++){
      double real = 0, imaginary = 0;
      for(x = 0; x < M; x++){
        for(y = 0; y < N; y++){
          double a = -2 * M_PI * (u * x + v * y) / N;
          real += R1[x][y] * cos(a) - I1[x][y] * sin(a);
          imaginary += I1[x][y] * cos(a) + R1[x][y] * sin(a);
        }
      }
      real = real / M;
      imaginary = imaginary / M;
      int f = sqrt(real * real + imaginary * imaginary);
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Image12->Canvas->Pixels[u][v] = (TColor) RGB( f,  f,  f);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  double M = Image2 -> Picture -> Bitmap -> Width;
  double N = Image2 -> Picture -> Bitmap -> Height;
  int u, v, x, y, d, d1 = 10;
  double real, image, p, da, m, e = 2.71828;
  double h[150][150], R1[150][150], I1[150][150];
  Image13 -> Width = Image2 -> Width;
  Image13 -> Height = Image2 -> Height;
  Image13 -> Picture -> Bitmap-> Height = Image2 -> Picture -> Bitmap -> Height;
  Image13 -> Picture -> Bitmap-> Width = Image2 -> Picture -> Bitmap -> Width;

  M = Image2 -> Width;
  N = Image2 -> Height;
  for(int u = 0;u < M;u++){
    for(int v = 0;v < N;v++){
      d = sqrt(pow(u - M / 2,2) + pow(v - N / 2,2));
      h[u][v] = 1 + (1 - pow(e,-pow(d,2) / (2 * pow(d1,2))));
    }
  }
  for(int u = 0;u < M;u++){
    for(int v = 0;v < N;v++){
      R1[u][v] = Real[u][v] * h[u][v] ;
      I1[u][v] = Imaginary[u][v] * h[u][v] ;
    }
  }
    for(u = 0; u < M; u++){
    for(v = 0; v < N; v++){
      double real = 0, imaginary = 0;
      for(x = 0; x < M; x++){
        for(y = 0; y < N; y++){
          double a = -2 * M_PI * (u * x + v * y) / N;
          real += R1[x][y] * cos(a) - I1[x][y] * sin(a);
          imaginary += I1[x][y] * cos(a) + R1[x][y] * sin(a);
        }
      }
      real = real / M;
      imaginary = imaginary / M;
      int f = sqrt(real * real + imaginary * imaginary);
      if(f>=255){f = 255;}
      else if(f <= 0){f = 0;}
      Image13->Canvas->Pixels[u][v] = (TColor) RGB( f,  f,  f);
    }
  }
}
//---------------------------------------------------------------------------

void colorquantization(int image_w, int image_h, int val){
  unsigned char R, G, B;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image1->Canvas->Pixels[i][j]);
      G = GetGValue(Form1->Image1->Canvas->Pixels[i][j]);
      B = GetBValue(Form1->Image1->Canvas->Pixels[i][j]);
      for(int k = 0; k < val; k++){
        R = (int)(R/2);
        G = (int)(G/2);
        B = (int)(B/2);
      }
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      R = GetRValue(Form1->Image14->Canvas->Pixels[i][j]);
      G = GetGValue(Form1->Image14->Canvas->Pixels[i][j]);
      B = GetBValue(Form1->Image14->Canvas->Pixels[i][j]);
      for(int k = 0; k < val; k++){
        R *= 2;
        G *= 2;
        B *= 2;
      }
      if(val==7){if(R!=0){R =255;}}
      if(val==7){if(G!=0){G =255;}}
      if(val==7){if(B!=0){B =255;}}
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}

void __fastcall TForm1::N2561282Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N126641Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N64322Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N32162Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1682Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 5);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N842Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 6);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N422Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  colorquantization(Image14->Width, Image14->Height, 7);
}
//---------------------------------------------------------------------------

int colormodel = 0; // RGB = 0, YIQ = 1  HSI = 2
double y_transform[256][256];
double i_transform[256][256];
double q_transform[256][256];
void __fastcall TForm1::RGBYIQ1Click(TObject *Sender)
{
  colormodel = 1;
  double Y, I, Q;
  double R, G, B;
  Image15->Width = Image1->Width;   Image15->Height = Image1->Height;
  for(int i = 0; i < Image1->Height; i++){
    for(int j = 0; j < Image1->Width; j++){
      R = GetRValue(Form1->Image1->Canvas->Pixels[i][j]);
      G = GetGValue(Form1->Image1->Canvas->Pixels[i][j]);
      B = GetBValue(Form1->Image1->Canvas->Pixels[i][j]);
      Y = 0.299*R + 0.587*G + 0.114*B;
      I = 0.596*R - 0.274*G - 0.322*B;
      Q = 0.211*R - 0.522*G + 0.311*B;
      y_transform[i][j] = Y;
      i_transform[i][j] = I;
      q_transform[i][j] = Q;
      Form1->Image15->Canvas->Pixels[i][j]=(TColor)RGB(Y, I, Q);
     }
  }
}
//---------------------------------------------------------------------------

double ii_transform[256][256];
double s_transform[256][256];
double h_transform[256][256];
double min(double R, double G, double B){
  double minrgb = R;
  if(minrgb > G){minrgb = G;}
  if(minrgb > B){minrgb = B;}
  return minrgb;
}
void __fastcall TForm1::RGBHSI1Click(TObject *Sender)
{
  colormodel = 2;
  double H, S, I;
  double R, G, B;
  double r, g, b, h, s, i;  //
  Image15->Width = Image1->Width;   Image15->Height = Image1->Height;
  for(int i = 0; i < Image1->Height; i++){
    for(int j = 0; j < Image1->Width; j++){
      R = GetRValue(Form1->Image1->Canvas->Pixels[i][j]);
      G = GetGValue(Form1->Image1->Canvas->Pixels[i][j]);
      B = GetBValue(Form1->Image1->Canvas->Pixels[i][j]);
      
      I = (R + G + B)/3.0;
      S = 1-((3*min(R, G, B)/((R + G + B))));
      if(S < 0){S = 0;}
      H = (int)acos((0.5*((R - G)+(R - B))) / sqrt(((R - G)*(R - G)) + (R - B) * (R - B)));
      if (H < 0)H = 0;
      else{
        H = (B > G) ? (360 - H) : H;
      }
      ii_transform[i][j] = I;
      s_transform[i][j] = S;
      h_transform[i][j] = H;

      /*
      r = R / (R + G + B);
      g = G / (R + G + B);
      b = B / (R + G + B);

      double radial;
      double value1 = 0.5 * ((r - g) + (r - b));
      double value2 = pow((pow(r - g, 2) + (r - b) * (g - b)), 0.5);
      int a = value1 / value2;
      radial = acos(a);
      int theta = (int)(radial * 180.0 / M_PI);
      if (theta < 0)h = 0;
      else{
        h = (b > g) ? (360 - theta) : theta;
      }
      s = 1 - 3 * min(r, g, b);
      if (s < 0)s = 0;
      i = (R + G + B) / 3.0;
      ii_transform[i][j] = i;
      s_transform[i][j] = s;
      h_transform[i][j] = h;
      */

      Form1->Image15->Canvas->Pixels[i][j]=(TColor)RGB(I, S, H);
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RGB2Click(TObject *Sender)
{
  double R, G, B;
  if(colormodel == 1){
    double Y, I, Q;
    for(int i = 0; i < Image15->Height; i++){
      for(int j = 0; j < Image15->Width; j++){
        Y = y_transform[i][j];
        I = i_transform[i][j];
        Q = q_transform[i][j];
        R = Y + 0.956*I + 0.621*Q;
        G = Y + (-0.272*I) + (-0.649*Q);
        B = Y + (-1.106*I) + 1.703*Q;
        Form1->Image15->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
        colormodel = 0;
       }
    }
  }

  if(colormodel == 2){
    double S, I;
    int H;
    int sector; // RG = 1, GB = 2, GB = 3;
    for(int i = 0; i < Image15->Height; i++){
      for(int j = 0; j < Image15->Width; j++){
        I = ii_transform[i][j];
        S = s_transform[i][j];
        H = h_transform[i][j];

        if(H < 120){
          sector = 1;
        }
        else if(H >= 120 && H < 240){
          H = H - 120;
          sector = 2;
        }
        else if(H >= 240 && H < 360){
          H = H - 240;
          sector = 3;
        }
        int theta1 = H;
        int theta2 = 60 - H;
        if (theta2 < 0){theta2 += 360;}

        double a = I * (1 - S);
        double c = I * (1 + (S * cos(theta1) / cos(theta2)));
        double d = 3 * I - a - c;

        switch(sector){
          case 1:
            B = a; R = c; G = d; break;
          case 2:
            R = a; G = c; B = d; break;
          case 3:
            G = a; B = c; R = d; break;
        }
        //R *= 255;
        //G *= 255;
        //B *= 255;
        if (R > 255)R = 255;
        else if (R < 0)R = 0;

        if (G > 255)G = 255;
        else if (G < 0)G = 0;

        if (B > 255)B = 255;
        else if (B < 0)B = 0;

        Form1->Image15->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
        colormodel = 0;
       }
    }
  }

}
//---------------------------------------------------------------------------

double r_transform[256][256];
double g_transform[256][256];
double b_transform[256][256];
void yiq_quantization(int image_w, int image_h, int val){
  double Y, I, Q;
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      Y = y_transform[i][j];
      I = i_transform[i][j];
      Q = q_transform[i][j];

      for(int k = 0; k < val; k++){
        Y = (int)(Y/2);
        I = (int)(I/2);
        Q = (int)(Q/2);
      }
      r_transform[i][j] = Y;
      g_transform[i][j] = I;
      b_transform[i][j] = Q;
    }
  }
  for(int i = 0; i < image_h; i++){
    for(int j = 0; j < image_w; j++){
      Y = r_transform[i][j];
      I = g_transform[i][j];
      Q = b_transform[i][j];
      for(int k = 0; k < val; k++){
        Y *= 2;
        I *= 2;
        Q *= 2;
      }
      r_transform[i][j] = Y;
      g_transform[i][j] = I;
      b_transform[i][j] = Q;
      //if(val==7){
        //if(Y!=0){Y = 255;}
        //if(I!=0){I = 255;}
        //if(Q!=0){Q = 255;}
      //}
      Form1->Image15->Canvas->Pixels[i][j]=(TColor)RGB(Y, I, Q);
    }
  }
}


void __fastcall TForm1::N1281Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 1);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N641Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 2);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N321Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 3);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N161Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 4);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N81Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 5);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 6);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
  Image14->Width = Image1->Width;   Image14->Height = Image1->Height;
  yiq_quantization(Image14->Width, Image14->Height, 7);
  double R, G, B;
  for(int i = 0; i < Image14->Height; i++){
    for(int j = 0; j < Image14->Width; j++){
      R = r_transform[i][j] + 0.956*g_transform[i][j] + 0.621*b_transform[i][j];
      G = r_transform[i][j] + (-0.272*g_transform[i][j]) + (-0.649*b_transform[i][j]);
      B = r_transform[i][j] + (-1.106*g_transform[i][j]) + 1.703*b_transform[i][j];
      Form1->Image14->Canvas->Pixels[i][j]=(TColor)RGB(R, G, B);
    }
  }
}
//---------------------------------------------------------------------------

