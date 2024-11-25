#ifndef __ASD_LIST__
#define __ASD_LIST__

#include <iostream>
using namespace std;

template <typename DataType>
struct Node
{
  DataType data;
  Node* next;
  
  Node(DataType d = 0, Node* n = nullptr);
  Node(const Node& node2);
  bool operator==(const Node& node2) const;
  bool operator!=(const Node& node2) const;
};

template <typename DataType>
class listIterator
{
private:
	Node<DataType>* p;
public:
	listIterator(Node<DataType>* tmp);
	DataType& operator*();
	listIterator& operator++();
	listIterator operator++(int);
	bool operator==(const listIterator& it2) const;
	bool operator!=(const listIterator& it2) const;
};

template <typename DataType>
class List
{
  Node<DataType>* head;
//  Node<DataType>* tail; // по желанию

public:
  List();
  bool isEmpty();

  void InsertToHead(const DataType& d); // вставить элемент d первым

  DataType ViewHead(); // посмотреть первого
  
  void InsertToTail(const DataType& d); // вставить элемент d последним

  DataType ViewTail(); // посмотреть последнего
										
  void Delete(const DataType& d); // удалить звено со значением data = d											
  listIterator<DataType> begin(); // получить итератор на первое звено 

  listIterator<DataType> tail(); // получить итератор на последнее звено

  listIterator<DataType> end(); // получить итератор на конец списка

  ~List();

  List(const List& list2);
  
  List& operator=(const List& list2);
  
  void Clean(); // удалить все звенья  
  			
  void InsertAfter(const listIterator<DataType>& it, const DataType& d); // вставить элемент d после звена node

  listIterator<DataType> Search(const DataType& d); // найти указатель на звено со значением data = d
  
  void Delete(const listIterator<DataType>& it); // удалить звено со значением data = d	
										
  void Delete(const listIterator<DataType>& start, const listIterator<DataType>& finish);

  void DeleteAll(const DataType& d);

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке

  List Merge(const listIterator<DataType>& start, const List& list2); // создать список3, добавив список2 в текущий список после итератора 

  void MergeWith(const listIterator<DataType>& start, const List& list2); // в *this добавить список2 после итератора

  friend ostream& operator<<(ostream& os, const List<DataType>& l);

  friend istream& operator>>(istream& is, const List<DataType>& l);
  
  void MadeUnique(); // исключить повторяющиеся звенья

  bool Cycle();   // определить, есть ли цикл в списке

  void BreakCycle(); // "разомкнуть" цикл в списке

  std::string ToString(); // "зн 1; зн2; " 

  int GetSize(); // узнать число звеньев в списке
  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif