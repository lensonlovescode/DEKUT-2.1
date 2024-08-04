#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBJECTS 10

typedef struct {
	char name[50];
	int marks[MAX_SUBJECTS];
	int num_subjects;
	double average_marks;
	char grade;
} student;

char assign_grade(double marks);
void input_student_data(student *s);
double calculate_average_marks(student *s);
void print_transcript(student *s);

char assign_grade(double marks)
{
	if (marks >= 90) {
		return 'A';
	}
	else if (marks >= 80) {
		return 'B';
	}
	else if (marks >= 70) {
		return 'C';
	}
	else if (marks >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}

void input_student_data(student *s)
{
	int i;
	printf("Enter student name: ");
	scanf("%s", s->name);
	
	printf("Enter number of subjects: ");
	scanf("%d", &(s->num_subjects));
	
	for (i = 0; i < s->num_subjects; i++) {
		printf("Enter marks for subject %d: ", i + 1);
		scanf("%d", &(s->marks[i]));
	}
	
	s->average_marks = calculate_average_marks(s);
	s->grade = assign_grade(s->average_marks);
}

double calculate_average_marks(student *s) {
	int sum, i;

	sum = 0;
	for (i = 0; i < s->num_subjects; i++) {
		sum += s->marks[i];
	}
	
	return (double)sum / s->num_subjects;
}

void print_transcript(student *s)
{
	int i;
	FILE *file = fopen("transcript.csv", "w");
	
	if (file == NULL) {
		printf("Error opening file!\n");
		return;
	}
	
	fprintf(file, "Name: %s\n", s->name);
	fprintf(file, "Subject, Marks\n\n");
	
	for (i = 0; i < s->num_subjects; i++) {
		fprintf(file, "Subject %d, %d\n", i + 1, s->marks[i]);
	}
	
	fprintf(file, "Average Marks,%.2f\n", s->average_marks);
	fprintf(file, "Grade,%c\n", s->grade);
	
	fclose(file);
	printf("Transcript saved to transcript.csv\n");
}

int main() {
	student s;
	
	input_student_data(&s);
	print_transcript(&s);
	
	return 0;
}

