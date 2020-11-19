#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	void menuadmin();
	void loginadmin();
	void postbarang();
void updatebarang();
	void hapusbarang();
	void pantaubarang();
void pemenang();
	void hapusmember();

	void akunmember();
	void menumember();
	void regismember();
	void loginmember();
	void lihatbarang();
void pengumuman();

struct loginadmin{
	char uadmin[100], padmin[100];
	}admin;

struct akunmember{
	char nama[100],ttl[50],asal[50],user[100],pass[100],hp[100],rek[100];
	int ikut;
	}b;

struct barang{
	char nbarang[100],deskripsi[100],tanggal[100];
	int harga,bid;
	}barang;

	FILE *filemember;
	FILE *filemember2;
	FILE *filebarang;
	FILE *filebarang2;
	
char session[100];
int coba=0,ikutan=0;
char delmember[50], delbarang[50],pilih[100];

int main (){
	int n;
	system ("cls");
	printf ("\t\t======== SELAMAT DATANG DI FORUM LELANG DASKOM ========\n");
	
	printf ("*** MENU PILIHAN ***\n\n");
	printf ("1. Admin\n");
	printf ("2. Member\n");
	printf ("3. Exit\n\n");
	
	printf ("Pilih menu\t : ");
	scanf ("%d",&n); fflush(stdin);
	
	switch (n){
		case 1 : loginadmin(); break;
		case 2 : akunmember(); break;
		case 3 : exit(1);break;
		default : printf ("\n\n\t\t\t ##### TERIMA KASIH #####"); exit(1);break;
	}
}

void loginadmin (){
	system ("cls");
			printf("Masukan Username\t:");gets(admin.uadmin);fflush(stdin);
			printf("Masukan Password\t:");gets(admin.padmin);system ("cls");fflush(stdin);
		
			if ((strcmp(admin.uadmin,"admin")==0) && (strcmp(admin.padmin,"admin")==0))
			{
				fflush(stdin);
				printf ("\tLOGIN SUKSES !!\n\n");
				system ("pause");
				system ("cls");
				menuadmin();
			}
			else printf ("Login Gagal\n");getchar();
			system("cls");
			main();
}

void menuadmin (){
	int ma;
		system ("cls");
	printf ("\t\t======== SELAMAT DATANG ADMIN ========\n");
	printf ("1. Post Barang\n");
	printf ("2. Update Barang\n");
	printf ("3. Hapus Barang\n");
	printf ("4. Pantau Barang\n");
	printf ("5. Input Pemenang\n");
	printf ("6. Hapus Akun Member\n");
	printf ("7. Exit\n");
	
	printf ("Pilih menu\t : ");
	scanf ("%d",&ma); fflush(stdin);
	system ("cls");
	
	switch (ma){
		case 1 : postbarang(); break;
		case 2 : updatebarang(); break;
		case 3 : hapusbarang(); break;
		case 4 : pantaubarang(); break;
		case 5 : pemenang(); break;
		case 6 : hapusmember(); break;
		case 7 : main(); break;
		default : printf("Pilihan yang anda masukkan salah. Silahkan coba lagi.");system("pause");system("cls");menuadmin();
	}
}

void postbarang(){
	filebarang = fopen("databarang.dat","ab");
	system ("cls");
	printf ("\t\t#### SILAHKAN INPUT ####\n\n");
	
	printf ("Nama Barang\t\t : "); gets(barang.nbarang);
	printf ("Deskripsi Barang\t : "); gets(barang.deskripsi);
	printf ("Open Harga\t\t : "); scanf("%d",&barang.harga);
	printf ("Kelipatan Bid\t\t : "); scanf("%d",&barang.bid);getchar();
	printf ("Tanggal Berakhir\t : "); gets(barang.tanggal);
	printf ("\n\n >>>> BARANG ANDA SUDAH TERSIMPAN <<<");
	
	fwrite(&barang,sizeof(barang),1,filebarang);
	system ("pause");
	system ("cls");
	fclose (filebarang);
	menuadmin();
}

void akunmember(){
	
	int pilihanmember;
	system ("cls");
	printf ("\t\t===== SELAMAT DATANG DI LELANG DASKOM =====\n\n");
	printf ("1. Registrasi Akun\n");
	printf ("2. Login\n");
	printf ("3. Exit\n\n");
	
	printf ("Silahkan pilih menu\t : "); scanf ("%d",&pilihanmember); fflush(stdin);
	
	switch (pilihanmember){
		case 1 : regismember(); break;
		case 2 : loginmember(); break;
		case 3 : main(); break;
		default : printf("Pilihan yang anda masukkan salah. Silahkan coba lagi.");system("pause");system("cls");akunmember();
	}
}

void regismember(){ 
	filemember = fopen("datamember.dat","ab+");
	system ("cls");
	printf ("\t\t#### SILAHKAN INPUT ####\n\n");
	printf ("Username\t : "); gets(b.user);
	printf ("Password\t : "); gets(b.pass);
	system ("cls");
	
	printf ("\t\t\t***** ISI DATA *****\n\n");
	printf ("Nama Lengkap\t\t : "); gets(b.nama);
	printf ("Tempat & tanggal lahir\t : "); gets(b.ttl);
	printf ("Alamat\t\t\t : "); gets(b.asal);
	printf ("No. Telepon\t\t : "); gets(b.hp);
	printf ("No. Rek\t\t : "); gets(b.rek);
	printf ("\n\n >>>> DATA ANDA SUDAH TERSIMPAN <<<");
	
	fwrite(&b,sizeof(b),1,filemember);
	system ("pause");
	system ("cls");
	fclose (filemember);
	akunmember();
}

void loginmember (){
	
	struct banyakmember{
		char userm[100],passm[100];
	}z;
	filemember = fopen("datamember.dat","rb");
	system ("cls");
	printf ("\t\t#### SELAMAT DATANG !! SILAHKAN LOGIN TERLEBIH DAHULU ####\n\n");
	if(coba<3){
		printf ("Username\t : "); gets(z.userm);
		printf ("Password\t : "); gets (z.passm);
		while(fread(&b,sizeof(b),1,filemember)==1){
			if ((strcmp(b.user,z.userm)!=0) || (strcmp(b.pass,z.passm)!=0)){
				printf("\n\n\t\t\t\t\t\t## Username dan Password Salah ##\n\n");
				getchar();
				coba++;
				loginmember();
			}
			else{
			printf("Login Berhasil\n");
			strcpy(session,b.user);
			system ("pause"); system ("cls");
			menumember();
			}
		}
	}
	else printf ("Percobaan Habis");
	coba=0;
	fclose (filemember);
	system("pause");system ("cls");
	akunmember(); 
}

void menumember(){ 
	int pil;
	printf ("\t\t======== SELAMAT DATANG MEMBER ========\n");
	printf ("1. Lihat dan Bid Barang\n");
	printf ("2. Cek Status Bid Barang\n");
	printf ("3. Exit\n");
	printf ("Pilih menu\t : ");
	scanf ("%d",&pil); fflush(stdin);
	system ("cls");
	
	switch (pil){
		case 1 : lihatbarang(); break;
		case 2 : pengumuman(); break;
		case 3 : main(); break;
		default : printf("Pilihan yang anda masukkan salah. Silahkan coba lagi.");system("pause");system("cls");menumember();
	}
}

void hapusmember(){
	filemember = fopen("datamember.dat", "rb+"); 
	filemember2 = fopen("datamember2.dat", "wb+");
	while (fread(&b,sizeof(b),1,filemember)!=0){
		printf ("\nUsername\t : %s",b.user);
		printf ("\nPassword\t : %s\n\n",b.pass);
	}
	printf("\n\nPilih akun member yang ingin dihapus (berdasarkan username)\t : "); gets(delmember); 
 
	while (fread(&b,sizeof (b),1, filemember)==1){ 
		if (strcmp(delmember,b.user)!=0){  
			fwrite(&b, sizeof(b), 1, filemember2); 
		} 
	}
 
	fclose(filemember); 
	fclose(filemember2); 
 
	remove("datamember.dat");
	rename("datamember2.dat","datamember.dat");
	printf("Penghapusan akun berhasil!");system("pause");system("cls");menuadmin(); 
}

void hapusbarang(){
	filebarang = fopen("databarang.dat", "rb"); 
	filebarang2 = fopen("databarang2.dat", "wb");
	
	printf ("\t\t#### SELAMAT DATANG DI MENU HAPUS BARANG ####\n\n");
	while (fread(&barang,sizeof(barang),1,filebarang)!=0){
		printf ("\nNama Barang\t\t : %s ",barang.nbarang);
		printf ("\nDeskripsi Barang\t : %s",barang.deskripsi);
		printf ("\nOpen Harga\t\t : %d ",barang.harga);
		printf ("\nKelipatan Bid\t\t : %d ",barang.bid);
		printf ("\nTanggal Berakhir\t : %s ",barang.tanggal);
		printf ("\nHarga Tertinggi\t\t : %d",b.ikut);
		printf ("\n\n=============================================\n\n");
	}
	
	printf("\n\nPilih barang yang ingin dihapus\t : "); gets(delbarang); 

	while (fread(&b,sizeof (b),1, filebarang)==1){ 
		if (strcmp(delbarang,barang.nbarang)!=0){
			fwrite(&b, sizeof(b), 1, filebarang2);
		}
	}
 
	fclose(filebarang); 
	fclose(filebarang2); 
 
	remove("databarang.dat");
	rename("databarang2.dat","databarang.dat");
	printf("Penghapusan barang berhasil!");system("pause");system("cls");menuadmin(); 
}

void lihatbarang(){
	filebarang = fopen("databarang.dat","rb+");
	filemember = fopen("datamember.dat","rb+");
	system ("cls");
	printf ("\t\t#### SELAMAT DATANG DI DAS'AUCTION ####\n\n");
	while (fread(&barang,sizeof(barang),1,filebarang)!=0){
		while (fread(&b,sizeof(b),1,filemember)!=0){
			printf ("\nNama Barang\t\t : %s ",barang.nbarang);
			printf ("\nDeskripsi Barang\t : %s",barang.deskripsi);
			printf ("\nOpen Harga\t\t : %d ",barang.harga);
			printf ("\nKelipatan Bid\t\t : %d ",barang.bid);
			printf ("\nTanggal Berakhir\t : %s ",barang.tanggal);
			printf ("\nHarga Tertinggi\t\t : %d oleh %s",b.ikut, b.nama);
			printf ("\n\n=============================================\n\n");
		}
	}
	printf ("Pilih Nama Barang\t : "); gets(pilih);
	printf ("Masukkan harga\t\t : "); scanf("%d",&ikutan);getchar();
	
	rewind(filebarang);
	rewind(filemember);
	while(fread(&barang,sizeof(barang),1,filebarang)!=0){
		while (fread(&b,sizeof(b),1,filemember)!=0){
			if(strcmp(pilih,barang.nbarang)==0 && (b.ikut<ikutan) && (barang.harga<ikutan) && (ikutan%barang.bid==0))
			{
				fseek(filemember,-sizeof(b),SEEK_CUR);
				b.ikut=ikutan;
				fwrite(&b,sizeof(b),1,filemember);
				printf("Bid anda berhasil tersimpan!\n\n");
				break;
			}
			else printf("Maaf, harga yang anda masukkan tidak dapat diterima");
		}
	}
	
	system ("pause");
	system ("cls");
	fclose (filebarang);
	fclose (filemember);
	menumember();
}

void pantaubarang(){
	filebarang = fopen("databarang.dat","rb+");
	filemember = fopen("datamember.dat","rb+");
	system ("cls");
	printf ("\t\t#### SELAMAT DATANGDI MENU PANTAU BARANG ####\n\n");
	while (fread(&barang,sizeof(barang),1,filebarang)!=0){
		while (fread(&b,sizeof(b),1,filemember)!=0){
			printf ("\nNama Barang\t\t : %s ",barang.nbarang);
			printf ("\nDeskripsi Barang\t : %s",barang.deskripsi);
			printf ("\nOpen Harga\t\t : %d ",barang.harga);
			printf ("\nKelipatan Bid\t\t : %d ",barang.bid);
			printf ("\nTanggal Berakhir\t : %s ",barang.tanggal);
			printf ("\nHarga Tertinggi\t\t : %d oleh %s ",b.ikut,b.nama);
			printf ("\n\n=============================================\n\n");
		}
	}
	
	system ("pause");
	system ("cls");
	fclose (filebarang);
	menuadmin();
}

void pemenang(){
	printf("Hello world");
}

void updatebarang(){
	filebarang = fopen("databarang.dat","rb+");
	while(fread(&barang,sizeof(barang),1,filebarang)!=0){
		printf ("\nNama Barang\t\t : %s ",barang.nbarang);
		printf ("\nDeskripsi Barang\t : %s",barang.deskripsi);
		printf ("\nOpen Harga\t\t : %d ",barang.harga);
		printf ("\nKelipatan Bid\t\t : %d ",barang.bid);
		printf ("\nTanggal Berakhir\t : %s ",barang.tanggal);
	}
	printf("Nama barang yang ingin di update : ");gets(delbarang);
	rewind(filebarang);
	while(fread(&barang,sizeof(barang),1,filebarang)==1){
		if(strcmp(delbarang,barang.nbarang)==0){
			fseek(filebarang,-sizeof(barang),SEEK_CUR);
			printf ("Nama Barang\t\t : "); gets(barang.nbarang);
			printf ("Deskripsi Barang\t : "); gets(barang.deskripsi);
			printf ("\n\n >>>> BARANG SUDAH DI UPDATE <<<");
			fwrite(&barang,sizeof(barang),1,filebarang);
		}
	}
	fclose(filebarang);
	pantaubarang();
}

void pengumuman(){
	printf("Hello world");
}


