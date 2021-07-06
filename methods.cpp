#include "classes.h"

Teacher* GetTl(forward_list<Teacher*> list, int x)
{
	forward_list<Teacher*>::iterator it = list.before_begin();
	for (int i = 0; i < x; i++) {
		it++;
	}
	return *it;
}

Lesson* GetLl(forward_list<Lesson*> list, int x)
{
	forward_list<Lesson*>::iterator it = list.before_begin();
	for (int i = 0; i < x; i++) {
		it++;
	}
	return *it;
}

char* Menu::isUnique(char *name)
{
	for (auto i : tl) {
		if (strcmp(i->getName(), name) == 0) {
			cout << "\n��� ������ ���� ���������, ��������� ����\n";
			do {
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(name, 100);
			} while (strcmp(i->getName(), name) == 0);
		}
	}
	return name;
}
char* Menu::CheckTime(char *time)
{
	while ((cin.fail()) || (time[2] != ':') || (isalpha(time[0]) == 1 || isalpha(time[1]) == 1 || isalpha(time[3]) == 1 || isalpha(time[4]) == 1)) {
		cout << "\n������ �����, ���������� ��� ���: ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> time;
	}
	return time;
}
int Menu::CheckInput(int x)
{
	while (cin.fail()) {
		cout << "\n������ �����, ���������� ��� ���: ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> x;
	}
	return x;
}
void Menu::Sort()
{
	Comparator *temp = new Comparator;
	ll.sort(Comparator());
	if (temp->getFlag() == false) {
		ll.sort(TimeComparator());
	}
}
void Menu::PrintLessons()
{
	bool flag = false;
	for (auto i : ll) {
		flag = true;
		cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
			<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
	}
	if (flag == false) {
		cout << "\n\n������ ����";
	}
}
bool Menu::FindLesson(bool flag, char *str, int choise)
{
	cout << "-------------------------------------------------";
	iterL = ll.before_begin();
	switch (choise) {
	case 1: {
		for (auto i : ll) {
			if (strcmp(i->getLesson(), str) == 0) {
				flag = true;
				cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
					<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
			}
		}
	}
	case 2: {
		for (auto i : ll) {
			if (strcmp(i->getType(), str) == 0) {
				flag = true;
				cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
					<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
			}
		}
	}
	case 3: {
		for (auto i : ll) {
			if (strcmp(i->getTimeSt(), str) == 0) {
				flag = true;
				cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
					<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
			}
		}
	}
	case 4: {
		for (auto i : ll) {
			if (strcmp(i->getTimeEd(), str) == 0) {
				flag = true;
				cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
					<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
			}
		}
	}
	case 5: {
		for (auto i : ll) {
			if (strcmp(i->getGroup(), str) == 0) {
				flag = true;
				cout << "\n\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType() << "\n| ������: " << i->getGroup()
					<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
			}
		}
	}
	}
	return flag;
}
void Menu::PrintTeacher()
{
	bool flag = false;
	for (auto i : tl) {
		flag = true;
		cout << "\n\n| ��� �������������: " << i->getName() << "\n| ������ ���������, ������� �� ����: " << i->getSubj();
	}
	if (flag == false) {
		cout << "\n\n������ ����";
	}
}
void Menu::AddTeacherToList()
{
	int temp1, temp2, temp3, counter;
	cout << "-------------------------------------------------\n";
	cout << "\n�������� �������������";
	counter = 0;
	cout << "\n-------------------------------------------------";
	for (auto i : tl) {
		counter++;
		cout << "\n\n| " << counter << ":\n| ��� �������������: " << i->getName() << "\n| ������ ���������, ������� �� ����: " << i->getSubj();
	}
	cout << endl << endl << "����: ";
	cin >> temp1;
	system("cls");
	counter = 0;
	cout << "-------------------------------------------------\n";
	cout << "\n�������� �������";
	counter = 0;
	cout << "\n-------------------------------------------------";
	for (auto i : ll) {
		counter++;
		cout << "\n\n| " << counter << ":\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType()
			<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd();
	}
	cout << endl << endl << "����: ";
	cin >> temp2;
	system("cls");
	cout << "-------------------------------------------------\n";
	cout << "\n�������� ���� ������ ��� �������";
	cout << "\n--------------------------------";
	shedule->getDays();
	cout << endl << endl << "����: ";
	cin >> temp3;
	temp3--;
	cout << "\n---------------------------------------\n";
	Teacher *tmp1 = new Teacher;
	Lesson *tmp2 = new Lesson;
	Shedule *tmp3 = new Shedule;
	tmp1 = GetTl(tl, temp1);
	tmp2 = GetLl(ll, temp2);
	tmp3->setAll(tmp2, tmp1, temp3);
	bool flag = true;
	for (auto i : ss) {
		if (i->getOneDay(i->getDayNum()) == tmp3->getOneDay(tmp3->getDayNum()) && strcmp(i->getTimeSt(), tmp3->getTimeSt()) == 0) {
			flag = false;
		}
	}
	if (flag == true) {
		ss.insert(tmp3);
	}
}
void Menu::PrintAll()
{
	if (ss.empty()) {
		cout << "\n\n������ ����\n\n";
		cout << "-------------------------------------------------------\n";
		return;
	}
	int counter = 0;
	iterS = ss.begin();
	for (int i = 0; i < 6; i++) {
		bool flag = false;
		cout << endl << shedule->getOneDay(counter) << ":";
		cout << "\n--------------------------------------------";
		for (auto i : ss) {
			if (i->getDayNum() == counter) {
				flag = true;
				cout << "\n| �������: " << i->getLesson() << "\n| ������: " << i->getGroup() << "\n| ��� �������: " << i->getType()
					<< "\n| ����� �������: " << i->getTimeSt() << "-" << i->getTimeEd() << "\n| ����: " << i->getName() << endl;
			}
		}
		if (flag == false) {
			cout << "\n������� ���\n";
		}
		cout << "--------------------------------------------\n";
		counter++;
	}
	cout << "\n-------------------------------------------------------\n";
}
void Menu::DeleteTeacherFromList() 
{
	int temp1, temp2, counter;
	char *tn = new char[100];
	char *lt = new char[6];
	const char *ld = new char;
	counter = 0;
	cout << "-------------------------------------------------\n";
	cout << "\n�������� �������������";
	cout << "\n-------------------------------------------------";
	for (auto i : ss) {
		counter++;
		cout << "\n\n| " << counter << ":\n| ��� �������������: " << i->getName() << "\n| ������ ���������, ������� �� ����: " << i->getSubj();
	}
	cout << endl << endl << "����: ";
	cin >> temp1;
	temp1--;
	counter = 0;
	for (auto i : tl) {
		if (temp1 == counter) {
			tn = i->getName();
			break;
		}
		counter++;
	}
	system("cls");
	cout << "-------------------------------------------------\n";
	cout << "\n�������� �������, ������� �� ����";
	counter = 0;
	cout << "\n-------------------------------------------------";
	for (auto i : ss) {
		if (strcmp(i->getName(), tn) == 0) {
			counter++;
			cout << "\n\n| " << counter << ":\n| �������� ��������: " << i->getLesson() << "\n| ��� �������: " << i->getType()
				<< "\n| ����� ������ � ���������: " << i->getTimeSt() << "-" << i->getTimeEd() << "\n| ���� ����������: " << i->getOneDay(i->getDayNum());
		}
	}
	cout << endl << endl << "����: ";
	cin >> temp2;
	temp2--;
	counter = 0;
	for (auto i : ss) {	
		if (strcmp(i->getName(), tn) == 0) {
			if (counter == temp2) {
				lt = i->getTimeSt();
				ld = i->getOneDay(counter);
				break;
			}
			counter++;
		}
	}
	counter = 0;
	for (auto i : ss) {
		if (strcmp(i->getName(), tn) == 0) {
			if ((i->getOneDay(counter) == ld) && (i->getTimeSt() == lt)) {
				ss.erase(i);
				break;
			}
			counter++;
		}
	}
}

forward_list<Lesson*> Menu::AddLesson(char *name, char *st, char *ed, char *gr, const char *type, int choise)
{
	Lesson *temp = new Lesson;
	switch (choise) {
	case 1: {
		type = "������";
		break;
	}
	case 2: {
		type = "��������";
		break;
	}
	case 3: {
		type = "������������";
		break;
	}
	case 4: {
		type = "��������";
		break;
	}
	}
	temp->set(name, type, st, ed, gr);
	ll.push_front(temp);
	return ll;
}
forward_list<Lesson*> Menu::DeleteLesson(char *name, char *group, const char *type, int choise)
{
	Lesson *temp = new Lesson;
	switch (choise) {
	case 1: {
		type = "������";
		break;
	}
	case 2: {
		type = "��������";
		break;
	}
	case 3: {
		type = "������������";
		break;
	}
	case 4: {
		type = "��������";
		break;
	}
	}
	iterL = ll.before_begin();
	for (auto i : ll) {
		if ((strcmp(i->getLesson(), name) == 0) && (strcmp(i->getType(), type) == 0) && (strcmp(i->getGroup(), group)) == 0) {
			temp = i;
			ll.erase_after(iterL);
			break;
		}
		iterL++;
	}
	for (auto i : ss) {
		if (i->getTimeSt() == temp->getTimeSt() && i->getLesson() == temp->getLesson() && i->getTimeEd() == temp->getTimeEd() && i->getType() == temp->getType()) {
			ss.erase(i);
			break;
		}
	}
	return ll;
}

forward_list<Teacher*> Menu::AddTeacher(char *name, char *subj)
{
	Teacher *temp = new Teacher;
	temp->set(name, subj);
	for (auto i : tl) {
		if (i == temp) {
			return tl;
		}
	}
	tl.push_front(temp);
	return tl;
}
forward_list<Teacher*> Menu::DeleteTeacher(char *name)
{
	Teacher *temp = new Teacher;
	iterT = tl.before_begin();
	for (auto i : tl) {
		if (strcmp(i->getName(), name) == 0) {
			temp = i;
			tl.erase_after(iterT);
			break;
		}
		iterT++;
	}
	return tl;
}

Shedule::Shedule()
{
	days.push_back("�����������");
	days.push_back("�������");
	days.push_back("�����");
	days.push_back("�������");
	days.push_back("�������");
	days.push_back("�������");
	curDay = "";
	shedLess = new Lesson;
	shedTeach = new Teacher;
}
void Shedule::getDays()
{
	for (int i = 0; i < 6; i++) {
		cout << "\n| " << i + 1 << ": " << days.at(i);
	}
}
int Shedule::getDayNum()
{
	if (strcmp(curDay, "�����������") == 0) {
		return 0;
	}
	else if (strcmp(curDay, "�������") == 0) {
		return 1;
	}
	else if (strcmp(curDay, "�����") == 0) {
		return 2;
	}
	else if (strcmp(curDay, "�������") == 0) {
		return 3;
	}
	else if (strcmp(curDay, "�������") == 0) {
		return 4;
	}
	else if (strcmp(curDay, "�������") == 0) {
		return 5;
	}
	return -1;
}

bool Comparator::operator()(Lesson *x, Lesson *y)
{
	if (x->lessonType == y->lessonType) {
		setFlag();
	}
	return x->lessonType > y->lessonType;
}