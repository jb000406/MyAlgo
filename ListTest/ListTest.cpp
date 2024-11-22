// ListTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

struct  Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;     //맨 앞에 있는 노드
    
public:
    //생성자
    LinkedList() : head(NULL) {};
    //소멸자
    ~LinkedList()
    {
        //생성한 node의 메모리 해제
        while (!empty())
        {
            pop_front();
        }
    }

    //매개변수를 데이터(value)를 입력받아 리스트 맨 앞에 삽입하기
    void push_front(int value)
    {
        //데이터(value)를 가진 노드 생성
        Node* new_node = new Node{value, NULL };

        if (head != NULL)
        {
            new_node->next = head;
        }

        head = new_node;

    }

    //리스트 맨 앞에 있는 데이터 삭제하기
    void pop_front()
    {
        if (head == NULL)
            return;

        Node* first = head;
        head = head->next;
        delete first;
    }

    //리스트의 모든 노드 데이터 출력
    void print_all()
    {
        Node* curr = head;

        //curr가 null이 될때까지 반복
        while (curr != NULL)
        {
            //현재 curr 노드의 데이터를 출력
            cout << curr->data << ", ";

            //curr 노드가 다음 노드로 이동한다
            curr = curr->next;
        }
        cout << endl;
    }

    //데이터 유무
    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
