// SortTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

//버블 정렬
void bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
            }
        }
    }
}

//선택 정렬
void selection_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;        //정렬되지 않은 데이터중에 최소값을 가진 데이터의 인덱스    :
        for (int j = i + 1; j < n; j++)
        {
            if (data[j] < data[idx])
            {
                idx = j;
            }
        }
        swap(data[i], data[idx]);
    }
}

//삽입 정렬
void insertion_sort(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = data[i];  //정렬되지 않은 데이터의 맨 왼쪽 값
        int j = i - 1;      //정렬되지 않은 데이터의 바로 앞 자리
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

//병합
int buff[256];

void merge(int data[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
        {
            buff[k++] = data[i++];
        }
        else
        {
            buff[k++] = data[j++];
        }
    }

    //왼쪽에 데이터가 남아있으면
    while (i <= mid)
    {
        buff[k++] = data[i++];
    }
    //오른쪽에 데이터가 남아있으면
    while (j <= right)
    {
        buff[k++] = data[j++];
    }

    //임시변수에 저장된 데이터를 다시 옮기기
    for (int x = left; x <= right; x++)
    {
        data[x] = buff[x];
    }
}

//병합정렬
// left: 정렬할 데이터의 맨 앞, right: 정렬할 데이터의 맨 뒤
void merge_sort(int data[], int left, int right)
{
    int mid = (left + right) / 2;
    merge_sort(data, left, mid);
    merge_sort(data, mid + 1, right);
    merge(data, left, mid, right);
}

//분할
int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left + 1;
    int j = right;
    while (true)
    {
        //i의 위치를 pivot 보가 큰값 까지 이동
        while (data[i] <= pivot && i <= right)
        {
            i++;
        }

        //j의 위치를 pivot 보가 작은값 까지 이동
        while (data[j] > pivot && j > left)
        {
            j--;
        }

        //이동이 완료되면
        if (i < j)
        {
            swap(data[i], data[j]);
        }
        else
        {
            break;
        }
    }
    swap(data[left], data[j]);

    return j;
}


//퀵 정렬
void quic_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int p = partition(data, left, right);
        quic_sort(data, left, p - 1);
        quic_sort(data, p + 1, right);
    }
}

int main()
{
    int data[] = { 5, 6, 7, 3, 1, 9, 2, 4, 8 };
    quic_sort(data, 0, size(data) - 1);

    for (auto n : data)
    {
        cout << n << ", ";
    }
    cout << endl; 

    /*int data[] = { 2, 6, 7, 4, 1, 8, 5, 3 };
    merge_sort(data, 0, 7);

    for (auto n : data)
    {
        cout << n << ", ";
    }
    cout << endl;*/

    //int data[] = { 4, 2, 3, 5, 1 };
    ////bubble_sort(data, 5);
    ////selection_sort(data, 5);
    //insertion_sort(data, 5);

    //for (auto n : data)
    //{
    //    cout << n << ", ";
    //}
    //cout << endl;
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
