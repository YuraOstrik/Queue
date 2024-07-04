#include <iostream>
#include <ctime>
using namespace std;

class Client {
	static int c__count;
	int id;

public:
	Client() : id(++c__count) {} // инициализация
	int GetId() const {
		return id;
	}
};

int Client::c__count = 0;

class Queue {
	int* wait;
	int maxLen;
	int Len;

public:
	Queue(int m);
	~Queue() {
		delete[] wait;
	}

	void Add(int c);
	int Extract();
	void Clean();

	bool IsEmpty() const;
	bool IsFull() const;

	int GetCount() const;

	void Show() const;
};

Queue::Queue(int m) {
	maxLen = m;
	wait = new int[maxLen];
	Len = 0;
}

void Queue::Clean() {
	Len = 0;
}

bool Queue::IsEmpty() const {
	return Len == 0;
}

bool Queue::IsFull() const {
	return Len == maxLen;
}

int Queue::GetCount() const {
	return Len;
}

void Queue::Add(int c) {
	if (!IsFull()) {
		wait[Len++] = c;
	}
}

int Queue::Extract() {
	if (!IsEmpty()) {
		int temp = wait[0];
		for (int i = 1; i < Len; i++) {
			wait[i - 1] = wait[i];
		}
		Len--;
		return temp;
	}
	else {
		cout << "Empty " << endl;
		return -1;
	}
}

void Queue::Show() const {
	cout << " --------------------------------- \n";
	for (int i = 0; i < Len; i++) {
		cout << wait[i] << "  ";
	}
	cout << " --------------------------------- \n";
}

class Print {
	Queue print;

public:
	Print(int len) : print(len) {}

	void Send(const Client& client) {
		if (print.IsFull()) {
			cout << "Printer is full // last - " << client.GetId() << endl;
		}
		else {
			print.Add(client.GetId());
			cout << "Client - " << client.GetId() << endl;
		}
	}

	void ShowQueue() const {
		std::cout << "Print Queue:";
		print.Show();
	}
};

int main() {
	Print func(20);

	for (int i = 0; i < 5; ++i) {
		Client client;
		func.Send(client);
		cout << endl;
	}

	
	for (int i = 0; i < 3; ++i) {
		func.ShowQueue();
		cout << endl;
	}


	

	return 0;
}





































