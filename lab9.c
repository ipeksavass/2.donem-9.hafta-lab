#include<stdio.h>
#include<stdlib.h>
void add_new_record();
void list_record();
void update_record();
void calculate_average();
void show_best();


struct student{
	int number;
	char name[15];
	float midGrade;
	float finalGrade;
};
struct student *yildiz = NULL;  
int ogr = 0;                    // number of students.

int main(){
	int option;                    
	
	do{
		printf("*************************************************\n");
		printf("Select an option [0,5]\n");
		printf("1-Add new record\n");
		printf("2-List records\n");
		printf("3-Update record\n");
		printf("4-Calculate average\n");
		printf("5-Show best student\n");
		scanf("%d",&option);
		
		switch(option){
		case 0:
			printf("The program is exiting...");
			break;
		case 1:
			add_new_record();
			break;
		case 2:
			list_record();
			break;
		case 3:
			update_record();
			break;
		case 4:
			calculate_average();
			break;
		case 5:
			show_best();
			break;
		
	}
	}while(option != 0);
	
	return 0;
}

	void add_new_record(){
	int num,i;     //num: number of students to be added.
	printf("num:");
	scanf("%d",&num);
	yildiz = (struct student*) realloc(yildiz,(ogr+num)*sizeof(struct student));
	
	for(i=0;i<num;i++){
		printf("new record:%d\n",i+1);
		printf("student number:");  	scanf("%d",&yildiz[i].number);
		printf("name:");   				scanf("%s",yildiz[i].name);
		printf("midterm grade:");   	scanf("%f",&yildiz[i].midGrade);
		printf("final grade:");    		scanf("%f",&yildiz[i].finalGrade);
	}
	
	ogr += num;
	printf("%d records added\n",num);
}

void list_record(){
	int i,j,choose;
	float min_midterm;
	float max_midterm;
	
	if(ogr == 0){
		printf("no record found\n");
		return;
	}
	
	printf("1-Sort by student number\n2-Sort by grade\n3-Default sort\n");
	scanf("%d",&choose);
	
	if(choose==1){
		for(i=0;i<ogr-1;i++){
			for(j=0;j<ogr-i-1;j++){
				if(yildiz[j].number > yildiz[j+1].number){
					struct student temp;
					temp = yildiz[j];
					yildiz[j] = yildiz[j+1];
					yildiz[j+1] = temp;
				}
			}
		}
		printf("%-10s  %-20s  %-15s  %-15s\n","number","name","midterm grade","final grade");
		for(i=0;i<ogr;i++){
			printf("%-10d  %-20s  %-15.2f  %-15.2f\n",yildiz[i].number,yildiz[i].name,yildiz[i].midGrade,yildiz[i].finalGrade);
		}
	}
	
	else if(choose==2){
		printf("Max midterm grade:");          scanf("%f",&max_midterm);
		printf("Min midterm grade:");          scanf("%f",&min_midterm);
		printf("%-10s  %-20s  %-15s  %-15s\n","number","name","midterm grade","final grade");
		for(i=0;i<ogr;i++){
		if(yildiz[i].midGrade>=min_midterm && yildiz[i].midGrade<=max_midterm)
		printf("%-10d  %-20s  %-15.2f  %-15.2f\n",yildiz[i].number,yildiz[i].name,yildiz[i].midGrade,yildiz[i].finalGrade);
		}
	}
	
	else if(choose==3){
		printf("%-10s  %-20s  %-15s  %-15s\n","number","name","midterm grade","final grade");
		for(i=0;i<ogr;i++){
			printf("%-10d  %-20s  %-15.2f  %-15.2f\n",yildiz[i].number,yildiz[i].name,yildiz[i].midGrade,yildiz[i].finalGrade);
		}
	}
	
}

void update_record(){
	int std_num,i;
	printf("Enter a student number for updating:\n");
	scanf("%d",&std_num);
	int found = 0;
	
	for(i=0;i<ogr;i++){
		if(yildiz[i].number == std_num){
			printf("Current student number:%d\n",yildiz[i].number);
			printf("New student number:");      		scanf("%d",&yildiz[i].number);
			
			printf("Current student name:%s\n",yildiz[i].name);    
			printf("New student name:");          		scanf("%s",yildiz[i].name);
		
			printf("Current student midterm grade:%.2f\n",yildiz[i].midGrade);
			printf("New student midterm grade:"); 		scanf("%f",&yildiz[i].midGrade);
		
			printf("Cyrrent student final grade:%.2f\n",yildiz[i].finalGrade);
			printf("New student final grade:");     	scanf("%f",&yildiz[i].finalGrade);
		}
		found = 1;
		break;
	}
	if(found==0)
		printf("Students are NOT found!");
}

void calculate_average(){
	int i = 0;
	float avg = 0.0;
	float grade = 0.0;
	
	for(i=0;i<ogr;i++){
		grade = grade + (yildiz[i].midGrade*0.4 + yildiz[i].finalGrade*0.6);
	}
	avg = grade / ogr;
	printf("The average is %.2f\n",avg);
}

void show_best(){
	float max = 0.0;
	float final_score = 0.0;
	int best=0;
	int i;
	max = yildiz[0].midGrade*0.4 + yildiz[0].finalGrade*0.6;
	for(i=0;i<ogr;i++){
		final_score = yildiz[i].midGrade*0.4 + yildiz[i].finalGrade*0.6;
		if(final_score>max){
			max = final_score;
			best=i;
		}
	}
	printf("%-10s   %-10s  %-10s   %-10s\n","number","name","midterm grade","final grade");
	printf("%-10d    %-10s   %-10.2f    %-10.2f\n",yildiz[best].number, yildiz[best].name, yildiz[best].midGrade, yildiz[best].finalGrade);
}


