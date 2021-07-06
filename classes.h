#pragma once 

#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <Windows.h>

using namespace std;

class Teacher
{
protected:
	char *teacherName = new char[100];
	char *subjects = new char[300];
public:
	Teacher() { teacherName = NULL, subjects = NULL; };
	void set(char *name, char *subj) { teacherName = name; subjects = subj; };
	virtual char* getName() { return teacherName; };
	virtual char* getSubj() { return subjects; };
	~Teacher() { delete teacherName; delete subjects; };
};

class Lesson
{
protected:
	char *group = new char[6];
	char *timeStart = new char[6];
	char *timeEnd = new char[6];
	char *lessonName = new char[30];
	const char *lessonType = new char[13];
public:
	Lesson() { lessonName = NULL, lessonType = NULL; timeStart = NULL;  timeEnd = NULL; group = NULL; };
	void set(char *name, const char *type, char *st, char *ed, char *gr) { lessonName = name; lessonType = type; timeStart = st; timeEnd = ed; group = gr; };
	virtual char* getLesson() { return lessonName; };
	virtual char* getTimeSt() { return timeStart; };
	virtual char* getTimeEd() { return timeEnd; };
	virtual char* getGroup() { return group; };
	virtual const char* getType() { return lessonType; };
	~Lesson() { delete lessonName; delete lessonType; delete timeStart; delete timeEnd; delete group; };
	friend class Comparator;
	friend class TimeComparator;
};

class Shedule : public Lesson, public Teacher
{
private:
	const char* curDay;
	vector<const char*> days;
	Lesson *shedLess;
	Teacher *shedTeach;
public:
	Shedule();
	void setAll(Lesson *lesson, Teacher *teacher, int day) { shedLess = lesson; shedTeach = teacher; curDay = days.at(day); }
	void getDays();
	int getDayNum();
	const char* getOneDay(int x) { return days.at(x); };
	virtual char* getName() { return shedTeach->getName(); };
	virtual char* getSubj() { return shedTeach->getSubj(); };
	virtual char* getGroup() { return shedLess->getGroup(); };
	virtual char* getLesson() { return shedLess->getLesson(); };
	virtual char* getTimeSt() { return shedLess->getTimeSt(); };
	virtual char* getTimeEd() { return shedLess->getTimeEd(); };
	virtual const char* getType() { return shedLess->getType(); };
	~Shedule() { delete curDay; delete shedLess; delete shedTeach; };
};

class Comparator {
private:
	bool flag = true;
public:
	bool operator()(Lesson *x, Lesson *y);
	void setFlag() { flag = false; };
	bool getFlag() { return flag; };
};

class TimeComparator {
public:
	bool operator()(Lesson *x, Lesson *y) { return x->timeStart > y->timeStart; };
};

class Menu
{
private:
	Teacher *teacher;
	Lesson *lesson;
	Shedule *shedule;
	forward_list<Teacher*> tl;
	forward_list<Teacher*>::iterator iterT;
	forward_list<Lesson*> ll;
	forward_list<Lesson*>::iterator iterL;
	unordered_set<Shedule*> ss;
	unordered_set<Shedule*>::iterator iterS;
public:
	Menu() { teacher = new Teacher; lesson = new Lesson; shedule = new Shedule; };
	int CheckInput(int x);
	forward_list<Lesson*> AddLesson(char *name, char *st, char *ed, char *group, const char *type, int x);
	forward_list<Lesson*> DeleteLesson(char *name, char *group, const char *type, int x);
	forward_list<Teacher*> AddTeacher(char *name, char *subj);
	forward_list<Teacher*> DeleteTeacher(char *name);
	void CallAddLesson(char *name, char *st, char *ed, char *group, int x) { ll = AddLesson(name, st, ed, group, lesson->getType(), x); };
	void CallDeleteLesson(char *name, char *group, int subj) { ll = DeleteLesson(name, group, lesson->getType(), subj); };
	void ClearLesson() { ll.clear(); ss.clear(); };
	void Sort();
	void PrintLessons();
	bool FindLesson(bool flag, char *str, int x);
	void CallAddTeacher(char *name, char *subj) { tl = AddTeacher(name, subj); };
	void CallDeleteTeacher(char *name) { tl = DeleteTeacher(name); };
	void ClearTeacher() { tl.clear(); ss.clear(); };
	void PrintTeacher();
	void AddTeacherToList();
	void DeleteTeacherFromList();
	void PrintAll();
	void ClearAll() { ss.clear(); };
	char* CheckTime(char *x);
	char* isUnique(char *name);
	~Menu() { delete teacher; delete lesson; delete shedule; };
};