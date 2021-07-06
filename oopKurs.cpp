#include "classes.h"

int main()
{
	system("color 4E");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu *menu = new Menu;
	int choose;
	startpoint:
	system("cls");
	cout << "--------------------------------" << "\n\n1 - Команды для занятий\n2 - Список преподавателей"
		<< "\n3 - Работа с расписанием\n\nДля выхода введите другую цифру" << "\n\n--------------------------------\n" << "Ввод: ";
	cin >> choose;
	choose = menu->CheckInput(choose);
	switch (choose) {
	case 1: {
		system("cls");
		cout << "--------------------------------------------------------" << "\n\n1 - Добавление занятия\n2 - Удаление занятия\n3 - Удаление всех занятий"
			<< "\n4 - Вывод занятий\n5 - Сортировка занятий\n6 - Поиск занятия\n\nДля возвращения к предыдущему меню введите другую цифру" 
			<< "\n\n--------------------------------------------------------\n" << "Ввод: ";
		cin >> choose;
		choose = menu->CheckInput(choose);
		switch (choose) {
		case 1: {
			system("cls");
			char *gr = new char[6];
			char *st = new char[6];
			char *ed = new char[6];
			char *name = new char[30];
			int choise;
			cout << "----------------------------------------------------------------------"
				<< "\n\nВведите название и тип предмета, а также время его начала и окончания";
			cout << "\n\nНазвание предмета: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(name, 30);
			cout << "\nВыберите тип занятия:\n1 - Лекция\n2 - Практика\n3 - Лабораторная\n4 - Курсовая\nТип занятия: ";
			cin >> choise;
			choise = menu->CheckInput(choise);
			cout << "\nВремя начала занятия в формате \'00:00\': ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(st, 6);
			st = menu->CheckTime(st);
			cout << "\nВремя окончания занятия в формате \'00:00\': ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(ed, 6);
			ed = menu->CheckTime(ed);
			cout << "\nВведите номер группы: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(gr, 6);
			menu->CallAddLesson(name, st, ed, gr, choise);
			break;
		}
		case 2: {
			system("cls");
			cout << "-------------------------------" << "\n\nВведите название и тип занятия";
			char *group = new char[6];
			char *name = new char[30];
			int temp;
			cout << "\n\nНазвание предмета: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(name, 30);
			cout << "\nНомер группы: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(group, 6);
			cout << "\nВыберите тип занятия:\n1 - Лекция\n2 - Практика\n3 - Лабораторная\n4 - Курсовая\nТип занятия: ";
			cin >> temp;
			temp = menu->CheckInput(temp);
			menu->CallDeleteLesson(name, group, temp);
			break;
		}
		case 3: {
			system("cls");
			menu->ClearLesson();
			break;
		}
		case 4: {
			system("cls");
			cout << "-------------------------------------------------";
			menu->PrintLessons();
			cout << "\n\n-------------------------------------------------\n";
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			menu->Sort();
			break;
		}
		case 6: {
			system("cls");
			char *str = new char[30];
			bool flag = false;
			cout << "-------------------------------";
			cout << "\n\nВыберите критерий поиска:\n| 1 - Название предмета\n| 2 - Тип предмета\n| 3 - Время начала занятия"
				<< "\n| 4 - Время окончания занятия\n| 5 - Номер группы" << "\n\n-------------------------------" << "\nВвод:";
			cin >> choose;
			choose = menu->CheckInput(choose);
			switch (choose) {
			case 1: {
				system("cls");
				cout << "-----------------------------";
				cout << "\n\nВведите название предмета: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(str, 30);
				system("cls");
				flag = menu->FindLesson(flag, str, choose);
				break;
			}
			case 2: {
				system("cls");
				int temp;
				cout << "------------------------";
				cout << "\n\nВыберите тип занятия:\n1 - Лекция\n2 - Практика\n3 - Лабораторная\n4 - Курсовая\n\n------------------------\nТип занятия: ";
				cin >> temp;
				temp = menu->CheckInput(temp);
				switch (temp) {
				case 1: {
					str = (char*)"Лекция";
					break;
				}
				case 2: {
					str = (char*)"Практика";
					break;
				}
				case 3: {
					str = (char*)"Лабораторная";
					break;
				}
				case 4: {
					str = (char*)"Курсовая";
					break;
				}
				}
				system("cls");
				flag = menu->FindLesson(flag, str, choose);
				break;
			}
			case 3: {
				system("cls");
				cout << "--------------------------------------------------";
				cout << "\n\nВведите время начала занятия в формате \'00:00\': ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(str, 6);
				str = menu->CheckTime(str);
				system("cls");
				flag = menu->FindLesson(flag, str, choose);
				break;
			}
			case 4: {
				system("cls");
				cout << "-----------------------------------------------------";
				cout << "\n\nВведите время окончания занятия в формате \'00:00\': ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(str, 6);
				str = menu->CheckTime(str);
				system("cls");
				flag = menu->FindLesson(flag, str, choose);
				break;
			}
			case 5: {
				system("cls");
				cout << "------------------------";
				cout << "\n\nВведите номер группы: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(str, 6);
				system("cls");
				flag = menu->FindLesson(flag, str, choose);
				break;
			}
			}
			if (flag == false) {
				cout << "\n\nСписок пуст";
			}
			cout << "\n\n-------------------------------------------------\n";
			system("pause");
			break;
		}
		}
		goto startpoint;
	}
	case 2: {
		system("cls");
		cout << "--------------------------------------------------------" << "\n\n1 - Добавление преподавателя\n2 - Удаление преподавателя"
			<< "\n3 - Удаление всех преподавателей\n4 - Вывод преподавателей\n\nДля возвращения к предыдущему меню введите другую цифру" 
			<< "\n\n--------------------------------------------------------\n" << "Ввод: ";
		cin >> choose;
		choose = menu->CheckInput(choose);
		switch (choose) {
		case 1: {
			system("cls");
			cout << "---------------------------------------------------------------" << "\n\nВведите имя преподавателя и список предметов, которые он ведёт";
			char *name = new char[100];
			char *subj = new char[300];
			cout << "\n\nФИО: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(name, 100);
			name = menu->isUnique(name);
			cout << "\nПредметы: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(subj, 300);
			menu->CallAddTeacher(name, subj);
			break;
		}
		case 2: {
			system("cls");
			cout << "----------------------------" << "\n\nВведите имя преподавателя";
			char *name = new char[100];
			cout << "\n\nФИО: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(name, 100);
			menu->CallDeleteTeacher(name);
			break;
		}
		case 3: {
			system("cls");
			menu->ClearTeacher();
			break;
		}
		case 4: {
			system("cls");
			cout << "-------------------------------------------------";
			menu->PrintTeacher();
			cout << "\n\n-------------------------------------------------\n";
			system("pause");
			break;
		}
		}
		goto startpoint;
	}
	case 3: {
		system("cls");
		cout << "--------------------------------------------------------" << "\n\n1 - Добавить занятие в расписание\n2 - Удалить предмет из расписания"
			<< "\n3 - Очистить расписание\n4 - Показать расписание\n\nДля возвращения к предыдущему меню введите другую цифру" 
			<< "\n\n--------------------------------------------------------\n" << "Ввод: ";
		cin >> choose;
		choose = menu->CheckInput(choose);
		switch (choose) {
		case 1: {
			system("cls");
			menu->AddTeacherToList();
			break;
		}
		case 2: {
			system("cls");
			menu->DeleteTeacherFromList();
			break;
		}
		case 3: {
			system("cls");
			menu->ClearAll();
			break;
		}
		case 4: {
			system("cls");
			cout << "-------------------------------------------------------";
			menu->PrintAll();
			system("pause");
			break;
		}
		}
		goto startpoint;
	}
	}
	system("pause");
}