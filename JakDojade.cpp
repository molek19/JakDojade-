#include "String.h"
#include "List.h"
#include <iostream>


using namespace std;

int map_heigh = 0; //w-row
int map_width = 0; //h-column

class List;
class Node;


bool isUpperCase(char** arr, int row, int col) {
    if (row < 0 || col < 0 || row>map_heigh - 1 || col>map_width - 1)
    {
        return 0;
    }
    else
    {
        if (arr[row][col] >= 'A' && arr[row][col] <= 'Z') {
            return true;
        }
        else {
            return false;
        }
    }

}

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty() {
        return head == nullptr;
    }

    // Funkcja dodaj¹ca nowy element na koniec kolejki
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (is_empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Funkcja usuwaj¹ca element z pocz¹tku kolejki i zwracaj¹ca jego wartoœæ
    int dequeue() {
        if (is_empty()) {
            std::cout << "Kolejka jest pusta!" << std::endl;
            return -1;
        }
        else {
            int val = head->number;
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return val;
        }
    }

    // Funkcja zwracaj¹ca wartoœæ pierwszego elementu kolejki bez usuwania go
    int peek() {
        if (is_empty()) {
            std::cout << "Kolejka jest pusta!" << std::endl;
            return -1;
        }
        else {
            return head->number;
        }
    }
    void clear() {
        while (!is_empty()) {
            dequeue();
        }
    }

};


//"."-puste pole(nieprzejezdne), "#"-droga(przejezdna ta jaki), "*"-znacznik na miasto(przejezdna jak "#"), "litera od miasta"-za chuja nieprzejzdna 
int main()
{


    int num_of_flight_connections = 0;
    int num_of_questions = 0;

    int index_purpose_flight = 1;//
    int index_source_flight = 1;//
    int index_time_flight = 1;// do listy przechowujacej info o lotach

    int index_source_questions = 1;//
    int index_purpose_questions = 1;//
    int index_type = 1;// do listy przechowujacej info o pytaniach

    int index_input = 0;
    int index_cities = 1;

    char pomocnicza1;
    String Input;
    List* source_question = new List();
    List* purpose_question = new List();
    List* type_question = new List();

    List* source_flight = new List();
    List* purpose_flight = new List();
    List* time_flight = new List();

    List* City = new List();
    List* City_X_Coord = new List();
    List* City_Y_Coord = new List();
    int x = 0;//x-owa miasta
    int y = 0;//y-owa miasta

    int searching_index_question_source = 1;
    int searching_index_question_purpose = 1;
    String searching_value_question_source;
    String searching_value_question_purpose;
    int searching_type_question = 0;
    int question_type = 0;
    int end_searching = 0;

    int index_path = 1;
    Queue PathXCoord;
    Queue PathYCoord;


    cin >> map_width >> map_heigh;

    String input = "";

    char** MAP = new char* [map_heigh];
    for (int k = 0; k < map_heigh; k++)
    {
        MAP[k] = new char[map_width]; //alokacja pamieci
        for (int p = 0; p < map_width; p++) //wpisanie wartosci do tablicy 
        {
            cin >> MAP[k][p]; //i - x coordinate, j - y coordinate          
        }
    }
    int** visited = new int* [map_heigh];
    for (int p = 0; p < map_heigh; p++)
    {
        visited[p] = new int[map_width];
        for (int z = 0; z < map_width; z++)
        {
            visited[p][z] = 0;
        }
    }
    for (int i = 0; i < map_heigh; i++)
    {
        for (int j = 0; j < map_width; j++)
        {

            if (isUpperCase(MAP, i, j) && !isUpperCase(MAP, i, j - 1) || isUpperCase(MAP, i, j) && j - 1 < 0)
            {

                pomocnicza1 = MAP[i][j];
                input += pomocnicza1;
                pomocnicza1 = 0;
                if (j - 1 >= 0)
                {
                    if (MAP[i][j - 1] == '*')
                    {
                        x = i;
                        y = j - 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (j + 1 <= map_width - 1)
                {
                    if (MAP[i][j + 1] == '*')
                    {
                        x = i;
                        y = j + 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (i - 1 >= 0)
                {
                    if (MAP[i - 1][j] == '*')
                    {
                        x = i - 1;
                        y = j;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j] == '*')
                    {
                        x = i + 1;
                        y = j;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    if (MAP[i - 1][j - 1] == '*')
                    {
                        x = i - 1;
                        y = j - 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (j + 1 <= map_width - 1 && i - 1 >= 0)
                {
                    if (MAP[i - 1][j + 1] == '*')
                    {
                        x = i - 1;
                        y = j + 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (j - 1 >= 0 && i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j - 1] == '*')
                    {
                        x = i + 1;
                        y = j - 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (j + 1 <= map_width - 1 && i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j + 1] == '*')
                    {
                        x = i + 1;
                        y = j + 1;
                        City_X_Coord->add_value_at_index(x, index_cities);
                        City_Y_Coord->add_value_at_index(y, index_cities);

                    }
                }
                if (j + 1 <= map_width - 1)
                {
                    if (!isUpperCase(MAP, i, j + 1))
                    {
                        City->add_value_at_index(input, index_cities);
                        input.clear();
                        index_cities++;
                    }
                }

            }
            else  if (isUpperCase(MAP, i, j) && isUpperCase(MAP, i, j - 1) && isUpperCase(MAP, i, j + 1))
            {
                pomocnicza1 = MAP[i][j];
                input += pomocnicza1;
                pomocnicza1 = 0;
            }


            else  if (isUpperCase(MAP, i, j) && !isUpperCase(MAP, i, j + 1) || isUpperCase(MAP, i, j) && j + 1 > map_width - 1)
            {
                pomocnicza1 = MAP[i][j];
                input += pomocnicza1;
                pomocnicza1 = 0;


                if (j - 1 >= 0)
                {
                    if (MAP[i][j - 1] == '*')
                    {
                        if (i == x && j - 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i;
                            y = j - 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }

                    }
                }
                if (j + 1 <= map_width - 1)
                {
                    if (MAP[i][j + 1] == '*')
                    {
                        if (i == x && j + 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i;
                            y = j + 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                    }
                }
                if (i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j] == '*')
                    {
                        if (i + 1 == x && j == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i + 1;
                            y = j;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                    }
                }
                if (i - 1 >= 0)
                {
                    if (MAP[i - 1][j] == '*')
                    {
                        if (i - 1 == x && j == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i - 1;
                            y = j;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }

                    }
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    if (MAP[i - 1][j - 1] == '*')
                    {
                        if (i - 1 == x && j - 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i - 1;
                            y = j - 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                    }
                }
                if (j + 1 <= map_width - 1 && i - 1 >= 0)
                {
                    if (MAP[i - 1][j + 1] == '*')
                    {
                        if (i - 1 == x && j + 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i - 1;
                            y = j + 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;

                        }
                    }
                }
                if (j - 1 >= 0 && i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j - 1] == '*')
                    {
                        if (i + 1 == x && j - 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i + 1;
                            y = j - 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                    }
                }
                if (j + 1 <= map_width - 1 && i + 1 <= map_heigh - 1)
                {
                    if (MAP[i + 1][j + 1] == '*')
                    {
                        if (i + 1 == x && j + 1 == y)
                        {
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                        else
                        {
                            x = i + 1;
                            y = j + 1;
                            City_X_Coord->add_value_at_index(x, index_cities);
                            City_Y_Coord->add_value_at_index(y, index_cities);
                            City->add_value_at_index(input, index_cities);
                            input.clear();
                            index_cities++;
                            continue;
                        }
                    }
                }
                City->add_value_at_index(input, index_cities);
                input.clear();
                index_cities++;
            }
        }
    }

    cin >> num_of_flight_connections;

    if (num_of_flight_connections != 0)
    {

        for (int i = 0; i < num_of_flight_connections; i++)
        {
            cin >> Input;
            source_flight->add_value_at_index(Input, index_source_flight);
            Input.clear();
            index_source_flight++;
            cin >> Input;
            purpose_flight->add_value_at_index(Input, index_purpose_flight);
            Input.clear();
            index_purpose_flight++;
            cin >> question_type;
            time_flight->add_value_at_index(question_type, index_time_flight);
            Input.clear();
            index_time_flight++;
        }
    }
    cin >> num_of_questions;
    if (num_of_questions != 0)
    {
        for (int i = 0; i < num_of_questions; i++)
        {
            cin >> Input;
            source_question->add_value_at_index(Input, index_source_questions);
            Input.clear();
            cin >> Input;
            purpose_question->add_value_at_index(Input, index_purpose_questions);
            Input.clear();
            cin >> question_type;
            type_question->add_value_at_index(question_type, index_type);
            searching_value_question_source = source_question->getValueAtIndexString(index_source_questions);
            searching_value_question_purpose = purpose_question->getValueAtIndexString(index_source_questions);
            if (searching_value_question_source == searching_value_question_purpose)
            {
                cout << 0 << endl;
            }
            else
            {
                if (City->contains_value(searching_value_question_source) == true && City->contains_value(searching_value_question_purpose) == true)
                {
                    searching_type_question = type_question->getValueAtIndexInt(index_source_questions);

                    searching_index_question_source = City->find_index(searching_value_question_source);
                    searching_index_question_purpose = City->find_index(searching_value_question_purpose);
                    int X_coord = City_X_Coord->getValueAtIndexInt(searching_index_question_source);
                    int Y_coord = City_Y_Coord->getValueAtIndexInt(searching_index_question_source);
                    int X_coord_1 = City_X_Coord->getValueAtIndexInt(searching_index_question_source);
                    int Y_coord_1 = City_Y_Coord->getValueAtIndexInt(searching_index_question_source);
                    int purpose_x = City_X_Coord->getValueAtIndexInt(searching_index_question_purpose);
                    int purpose_y = City_Y_Coord->getValueAtIndexInt(searching_index_question_purpose);
                    int searching_path_index = 1;
                    visited[X_coord][Y_coord] = 1;
                    int smth = 0;
                    int shorter_time = 0;
                    bool truefalse = false;
                    do
                    {
                        if (smth > 0)
                        {
                            X_coord = PathXCoord.peek();
                            Y_coord = PathYCoord.peek();
                            PathXCoord.dequeue();
                            PathYCoord.dequeue();

                        }
                        if (Y_coord - 1 >= 0)
                        {
                            if ((MAP[X_coord][Y_coord - 1] == '#' || MAP[X_coord][Y_coord - 1] == '*') && visited[X_coord][Y_coord - 1] == 0)
                            {

                                if (X_coord == purpose_x && Y_coord - 1 == purpose_y)
                                {
                                    visited[purpose_x][purpose_y] = visited[X_coord][Y_coord] + 1;
                                    end_searching = 1;
                                    continue;
                                }
                                else
                                {
                                    visited[X_coord][Y_coord - 1] = visited[X_coord][Y_coord] + 1;
                                    PathXCoord.enqueue(X_coord);
                                    PathYCoord.enqueue(Y_coord - 1);
                                }

                            }
                        }
                        if (Y_coord + 1 <= map_width - 1)
                        {
                            if ((MAP[X_coord][Y_coord + 1] == '#' || MAP[X_coord][Y_coord + 1] == '*') && visited[X_coord][Y_coord + 1] == 0)
                            {
                                if (X_coord == purpose_x && Y_coord + 1 == purpose_y)
                                {
                                    visited[purpose_x][purpose_y] = visited[X_coord][Y_coord] + 1;
                                    end_searching = 1;
                                    continue;
                                }
                                else
                                {
                                    visited[X_coord][Y_coord + 1] = visited[X_coord][Y_coord] + 1;
                                    PathXCoord.enqueue(X_coord);
                                    PathYCoord.enqueue(Y_coord + 1);
                                }

                            }
                        }
                        if (X_coord - 1 >= 0)
                        {
                            if ((MAP[X_coord - 1][Y_coord] == '#' || MAP[X_coord - 1][Y_coord] == '*') && visited[X_coord - 1][Y_coord] == 0)
                            {
                                if (X_coord - 1 == purpose_x && Y_coord == purpose_y)
                                {
                                    visited[purpose_x][purpose_y] = visited[X_coord][Y_coord] + 1;
                                    end_searching = 1;
                                    continue;
                                }
                                else
                                {
                                    visited[X_coord - 1][Y_coord] = visited[X_coord][Y_coord] + 1;
                                    PathXCoord.enqueue(X_coord - 1);
                                    PathYCoord.enqueue(Y_coord);
                                }

                            }
                        }
                        if (X_coord + 1 <= map_heigh - 1)
                        {
                            if ((MAP[X_coord + 1][Y_coord] == '#' || MAP[X_coord + 1][Y_coord] == '*') && visited[X_coord + 1][Y_coord] == 0)
                            {
                                if (X_coord + 1 == purpose_x && Y_coord == purpose_y)
                                {
                                    visited[purpose_x][purpose_y] = visited[X_coord][Y_coord] + 1;
                                    end_searching = 1;
                                    continue;
                                }
                                else
                                {
                                    visited[X_coord + 1][Y_coord] = visited[X_coord][Y_coord] + 1;
                                    PathXCoord.enqueue(X_coord + 1);
                                    PathYCoord.enqueue(Y_coord);
                                }

                            }
                        }
                        smth = 1;

                    } while (end_searching != 1);
                    if (num_of_flight_connections != 0)
                    {
                        for (int r = 1; r < index_source_flight; r++)
                        {
                            if (source_flight->getValueAtIndexString(r) == searching_value_question_source && purpose_flight->getValueAtIndexString(r) == searching_value_question_purpose)
                            {
                                if (time_flight->getValueAtIndexInt(r) < visited[purpose_x][purpose_y] - 1)
                                {
                                    shorter_time = time_flight->getValueAtIndexInt(r);
                                    truefalse = true;
                                    break;
                                }
                            }
                        }
                    }

                    if (searching_type_question == 0)
                    {
                        if (truefalse == true)
                        {
                            cout << shorter_time << endl;
                            truefalse = false;
                        }
                        else
                            cout << visited[purpose_x][purpose_y] - 1 << endl;
                    }
                    else if (searching_type_question == 1)
                    {
                        int visited_X = purpose_x;
                        int visited_Y = purpose_y;
                        int cos = 0;
                        int ender = 0;
                        int val_X = 0;
                        int val_Y = 0;
                        String path_cities[1000];
                        int index_path_cities = 0;
                        do
                        {
                            if (visited_X == X_coord_1 && visited_Y == Y_coord_1)
                            {
                                ender = 1;
                                continue;
                            }
                            if (visited_Y - 1 >= 0)
                            {
                                if (visited[visited_X][visited_Y] - 1 == visited[visited_X][visited_Y - 1])
                                {
                                    visited_X = visited_X;
                                    visited_Y = visited_Y - 1;
                                    if (City_X_Coord->contains_value(visited_X) && City_Y_Coord->contains_value(visited_Y))
                                    {
                                        for (int g = 1; g < City_X_Coord->getSize(); g++)
                                        {
                                            val_X = City_X_Coord->getValueAtIndexInt(g);
                                            val_Y = City_Y_Coord->getValueAtIndexInt(g);
                                            if ((val_X == visited_X) && (val_Y == visited_Y))
                                            {
                                                cos = g;
                                                String path_city = City->getValueAtIndexString(cos);
                                                path_cities[index_path_cities] = path_city;
                                                path_city.clear();
                                                index_path_cities++;
                                                break;
                                            }
                                        }
                                    }
                                    continue;
                                }
                            }
                            if (visited_Y + 1 <= map_width - 1)
                            {
                                if (visited[visited_X][visited_Y] - 1 == visited[visited_X][visited_Y + 1])
                                {
                                    visited_X = visited_X;
                                    visited_Y = visited_Y + 1;
                                    if (City_X_Coord->contains_value(visited_X) && City_Y_Coord->contains_value(visited_Y))
                                    {
                                        for (int g = 1; g < City_X_Coord->getSize(); g++)
                                        {
                                            val_X = City_X_Coord->getValueAtIndexInt(g);
                                            val_Y = City_Y_Coord->getValueAtIndexInt(g);
                                            if (val_X == visited_X && val_Y == visited_Y)
                                            {
                                                cos = g;
                                                String path_city = City->getValueAtIndexString(cos);
                                                path_cities[index_path_cities] = path_city;
                                                path_city.clear();
                                                index_path_cities++;
                                                break;
                                            }
                                        }
                                    }
                                    continue;
                                }
                            }
                            if (visited_X - 1 >= 0)
                            {
                                if (visited[visited_X][visited_Y] - 1 == visited[visited_X - 1][visited_Y])
                                {
                                    visited_X = visited_X - 1;
                                    visited_Y = visited_Y;
                                    if (City_X_Coord->contains_value(visited_X) && City_Y_Coord->contains_value(visited_Y))
                                    {
                                        for (int g = 1; g < City_X_Coord->getSize(); g++)
                                        {
                                            val_X = City_X_Coord->getValueAtIndexInt(g);
                                            val_Y = City_Y_Coord->getValueAtIndexInt(g);
                                            if (val_X == visited_X && val_Y == visited_Y)
                                            {
                                                cos = g;
                                                String path_city = City->getValueAtIndexString(cos);
                                                path_cities[index_path_cities] = path_city;
                                                path_city.clear();
                                                index_path_cities++;
                                                break;
                                            }
                                        }
                                    }
                                    continue;
                                }
                            }
                            if (visited_X + 1 <= map_heigh - 1)
                            {
                                if (visited[visited_X][visited_Y] - 1 == visited[visited_X + 1][visited_Y])
                                {
                                    visited_X = visited_X + 1;
                                    visited_Y = visited_Y;

                                    if (City_X_Coord->contains_value(visited_X) && City_Y_Coord->contains_value(visited_Y))
                                    {
                                        for (int g = 1; g < City_X_Coord->getSize(); g++)
                                        {
                                            val_X = City_X_Coord->getValueAtIndexInt(g);
                                            val_Y = City_Y_Coord->getValueAtIndexInt(g);
                                            if (val_X == visited_X && val_Y == visited_Y)
                                            {
                                                cos = g;
                                                String path_city = City->getValueAtIndexString(cos);
                                                path_cities[index_path_cities] = path_city;
                                                path_city.clear();
                                                index_path_cities++;
                                                break;
                                            }
                                        }

                                    }
                                    continue;

                                }
                            }

                        } while (ender != 1);
                        if (num_of_flight_connections != 0)
                        {
                            for (int r = 1; r < index_source_flight; r++)
                            {
                                if (source_flight->getValueAtIndexString(r) == searching_value_question_source && purpose_flight->getValueAtIndexString(r) == searching_value_question_purpose)
                                {
                                    if (time_flight->getValueAtIndexInt(r) < visited[purpose_x][purpose_y] - 1)
                                    {
                                        shorter_time = time_flight->getValueAtIndexInt(r);
                                        truefalse = true;
                                        break;
                                    }
                                }
                            }
                        }

                        if (truefalse == true)
                        {
                            cout << shorter_time << endl;
                            truefalse = false;
                        }
                        else
                        {
                            cout << visited[purpose_x][purpose_y] - 1 << " ";
                            if (!path_cities[0].is_empty())
                            {
                                for (int v = index_path_cities - 2; v >= 0; v--)
                                {
                                    cout << path_cities[v] << " ";
                                }
                                cout << endl;
                            }

                        }

                    }
                    smth = 0;
                    index_path = 1;
                    searching_path_index = 1;
                    end_searching = 0;
                    searching_value_question_purpose.clear();
                    searching_value_question_source.clear();
                    index_source_questions++;
                    index_purpose_questions++;
                    index_type++;
                    PathXCoord.clear();
                    PathYCoord.clear();
                    Input.clear();
                    for (int l = 0; l < map_heigh; l++)
                    {
                        for (int t = 0; t < map_width; t++)
                        {
                            visited[l][t] = 0;
                        }
                    }

                }
            }

        }
    }
    return 0;
}