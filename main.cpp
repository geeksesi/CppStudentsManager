#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class Science
{
private:
    /** 
     * [ [userid] = [ [lesson_id] = [X , number] ] ]
     * like : [0] = [
     *      0 = [3 12]  (Math)
     *      1 = [2 20]  (English)
     *      2 = [3 9]   (Geometry)
     *      3 = [2 8]   (Equations)
     * ]
     * 
     */
    int math_numbers[5][4][2];
    /**
     * [ [user_id] = ["name", "Average"] ]
     */
    string math_names[5][2];
    
    /** 
     * [ [userid] = [ [lesson_id] = [X , number] ] ]
     * like : [0] = [
     *      0 = [3 12]  (Math)
     *      1 = [2 20]  (English)
     *      2 = [3 9]   (Biology)
     *      3 = [2 8]   (Genetic)
     * ]
     * 
     */
    int experimental_numbers[5][4][2];
    /**
     * [ [user_id] = ["name", "Average"] ]
     */
    string experimental_names[5][2];

    /** 
     * [ [userid] = [ [lesson_id] = [X , number] ] ]
     * like : [0] = [
     *      0 = [3 12]  (Economy)
     *      1 = [2 8]   (English)
     *      2 = [3 9]   (Philosophy)
     *      3 = [2 20]  (History)
     * ]
     * 
     */
    int human_numbers[5][4][2];
    /**
     * [ [user_id] = ["name", "Average"] ]
     */
    string human_names[5][2];

public:

    /**
     * Read file, fill arrays, sort arrays
     */
    Science()
    {
        int math_counter = 0;
        int exp_counter = 0;
        int human_counter = 0;
        for (int i = 1; i < 16; i++)
        {
            string name;
            int number[4][2];
            double average;
            stringstream address;
            address << "data/"<<i<<".txt"; 
            string type_science = this->read_file(address.str().c_str(), name, &number[0][0], average);
            // cout << name << " \t " << average << " \t " << type_science << endl; 
            // cout <<i << " " <<  average<<endl;
            

            if (type_science == "math")
            {
                for (int b = 0; b < 4; b++)
                {
                    this->math_numbers[math_counter][b][0] = number[b][0];
                    this->math_numbers[math_counter][b][1] = number[b][1];
                }
                this->math_names[math_counter][0] = name;
                // cout << name << endl;
                this->math_names[math_counter][1] = to_string(average);
                math_counter++;
            } 
            else if (type_science == "experimental")
            {
                for (int b = 0; b < 4; b++)
                {
                    this->experimental_numbers[exp_counter][b][0] = number[b][0];
                    this->experimental_numbers[exp_counter][b][1] = number[b][1];
                }
                this->experimental_names[exp_counter][0] = name;
                this->experimental_names[exp_counter][1] = to_string(average);
                exp_counter++;
            } 
            else if (type_science == "human")
            {
                for (int b = 0; b < 4; b++)
                {
                    this->human_numbers[human_counter][b][0] = number[b][0];
                    this->human_numbers[human_counter][b][1] = number[b][1];
                }
                this->human_names[human_counter][0] = name;
                this->human_names[human_counter][1] = to_string(average);
                human_counter++;
            } 
        }
        
        this->sort_arrays();
        // for (int i = 0; i < 4; i++)
        // {
        //     for (int b = 0; b < 4; b++)
        //     {
        //         cout << human_names[i][0] << "\t" << human_names[i][1] << "\t" << human_numbers[i][b][0] << "\t" <<  human_numbers[i][b][1]<<endl;
        //     }
            
        // }
    }


    void sort_arrays()
    {
        for (int loop = 0; loop < 4; loop++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (stod( this->math_names[i][1] ) < stod( this->math_names[i+1][1] ))
                {
                    // swap math_name i and i+1 value
                    string tmp1[2] = {this->math_names[i][0], this->math_names[i][1]};
                    
                    this->math_names[i][0] = this->math_names[i+1][0]; 
                    this->math_names[i][1] = this->math_names[i+1][1]; 
                    this->math_names[i+1][0] = tmp1[0]; 
                    this->math_names[i+1][1] = tmp1[1]; 

                    // swap math_numbers i and i+1 value
                    int tmp2[4][2];
                    for (int j = 0; j < 4; j++)
                    {
                        tmp2[i][0] =  this->math_numbers[i][j][0];
                        this->math_numbers[i][j][0] = this->math_numbers[i+1][j][0];
                        this->math_numbers[i+1][j][0] = tmp2[i][0];

                        tmp2[i][1] =  this->math_numbers[i][j][1];
                        this->math_numbers[i][j][1] = this->math_numbers[i+1][j][1];
                        this->math_numbers[i+1][j][1] = tmp2[i][1];
                    }
                    
                }

                if (stod( this->experimental_names[i][1] ) < stod( this->experimental_names[i+1][1] ))
                {
                    // swap experimental_name i and i+1 value
                    string tmp1[2] = {this->experimental_names[i][0], this->experimental_names[i][1]};
                    this->experimental_names[i][0] = this->experimental_names[i+1][0]; 
                    this->experimental_names[i][1] = this->experimental_names[i+1][1]; 
                    this->experimental_names[i+1][0] = tmp1[0]; 
                    this->experimental_names[i+1][1] = tmp1[1]; 

                    // swap experimental_numbers i and i+1 value
                    int tmp2[4][2];
                    for (int j = 0; j < 4; j++)
                    {
                        tmp2[i][0] =  this->experimental_numbers[i][j][0];
                        this->experimental_numbers[i][j][0] = this->experimental_numbers[i+1][j][0];
                        this->experimental_numbers[i+1][j][0] = tmp2[i][0];
                        
                        tmp2[i][1] =  this->experimental_numbers[i][j][1];
                        this->experimental_numbers[i][j][1] = this->experimental_numbers[i+1][j][1];
                        this->experimental_numbers[i+1][j][1] = tmp2[i][1];
                    }
                    
                }
              if (stod( this->human_names[i][1] ) < stod( this->human_names[i+1][1] ))
                {
                    // swap human_name i and i+1 value
                    string tmp1[2] = {this->human_names[i][0], this->human_names[i][1]};
                    this->human_names[i][0] = this->human_names[i+1][0]; 
                    this->human_names[i][1] = this->human_names[i+1][1]; 
                    this->human_names[i+1][0] = tmp1[0]; 
                    this->human_names[i+1][1] = tmp1[1]; 

                    // swap human_numbers i and i+1 value
                    int tmp2[4][2];
                    for (int j = 0; j < 4; j++)
                    {
                        tmp2[i][0] =  this->human_numbers[i][j][0];
                        this->human_numbers[i][j][0] = this->human_numbers[i+1][j][0];
                        this->human_numbers[i+1][j][0] = tmp2[i][0];
                        
                        tmp2[i][1] =  this->human_numbers[i][j][1];
                        this->human_numbers[i][j][1] = this->human_numbers[i+1][j][1];
                        this->human_numbers[i+1][j][1] = tmp2[i][1];
                    }
                    
                }
                
            }
        }

        
        
    }

    /**
     * address must like : "data/1.txt"
     * 
     * 
     * return type = math | human | experimental
     */
    string read_file(string address, string &name, int *number, double &average)
    {
        ifstream file;
        file.open(address);
        string line, type, user_name = "";
        int tmp_arr[4][2];
        if (file.is_open())
        {
            int counter = 0;
            while (getline(file ,line))
            {
                if (counter == 0)
                {
                    stringstream s(line);
                    string a_part;
                    int count = 0;
                    while (s >> a_part)
                    {
                        if (count < 2)
                        {
                            user_name += (count == 0) ? a_part : " "+a_part;
                        }
                        else if (count == 2)                        
                        {
                            
                            if (a_part == "MathScience")
                            {
                                type = "math";
                            }
                            else if (a_part == "ExperimentalScience")
                            {
                                type = "experimental";
                            }
                            else if (a_part == "HumanScience")
                            {
                                type = "human";
                            }
                            else
                            {
                                cout << "wrong type of user Science";
                            }
                        }
                        
                        count++;
                    }
                    
                }

                if (counter != 0)
                {
                    stringstream s(line);
                    string a_part;
                    int count = 0;
                    int arr_pos;
                    while (s >> a_part)
                    {
                        if (type == "math" && count == 0)
                        {
                            if (a_part == "Math")
                            {
                                arr_pos = 0;
                            }
                            else if (a_part == "English")
                            {
                                arr_pos = 1;
                            }
                            else if (a_part == "Geometry")
                            {
                                arr_pos = 2;
                            }
                            else if (a_part == "Equations")
                            {
                                arr_pos = 3;
                            }
                        }
                        else if (type == "experimental" && count == 0)
                        {
                            if (a_part == "Math")
                            {
                                arr_pos = 0;
                            }
                            else if (a_part == "English")
                            {
                                arr_pos = 1;
                            }
                            else if (a_part == "Biology")
                            {
                                arr_pos = 2;
                            }
                            else if (a_part == "Genetic")
                            {
                                arr_pos = 3;
                            }
                        }
                        else if (type == "human" && count == 0)
                        {
                            if (a_part == "Economy")
                            {
                                arr_pos = 0;
                            }
                            else if (a_part == "English")
                            {
                                arr_pos = 1;
                            }
                            else if (a_part == "Philosophy")
                            {
                                arr_pos = 2;
                            }
                            else if (a_part == "History")
                            {
                                arr_pos = 3;
                            }
                        }
                        else if (count == 1)
                        {
                            tmp_arr[arr_pos][0] = atoi( a_part.c_str() );
                        }
                        else if (count == 2)
                        {
                            tmp_arr[arr_pos][1] = atoi( a_part.c_str() );
                        }
                        
                        
                        count++;
                    }
                }                
                counter++; 
                // cout << line << '\n';
            }
            file.close();
        }
        name = user_name;
        int tmp_average = 0;
        for (int i = 0; i < 4; i++)
        {
            // cout << ((user_name == "Mehdi Hatef") ? tmp_arr[i][1] * tmp_arr[i][0] : 1 )<<endl;
            tmp_average += tmp_arr[i][1] * tmp_arr[i][0];
            number[i * 2] = tmp_arr[i][0];
            number[i * 2 +1] = tmp_arr[i][1];
            // cout << number[i][1] << endl;

        }
        average = (double)(tmp_average / 4);
        // cout << user_name << tmp_average  << endl;
        return type;
    }

    
    /**
     * what  = best | bad
     */
    void print_in_all(string what)
    {
        if (what == "best")
        {            
            if (stod(this->math_names[0][1]) > stod(this->experimental_names[0][1]) &&  stod(this->math_names[0][1]) > stod(this->human_names[0][1]))
            {
                cout << "Best in all is : " << this->math_names[0][0] << " with Score : " << this->math_names[0][1]<<endl;
            }
            else if (stod(this->experimental_names[0][1]) > stod(this->math_names[0][1]) && stod(this->experimental_names[0][1]) > stod(this->human_names[0][1]))
            {
                cout << "Best in all is : " << this->experimental_names[0][0] << " with Score : " << this->experimental_names[0][1]<<endl;
            }
            else if (stod(this->human_names[0][1]) > stod(this->math_names[0][1]) && stod(this->human_names[0][1])> stod(this->experimental_names[0][1]))
            {
                cout << "Best in all is : " << this->human_names[0][0] << " with Score : " << this->human_names[0][1]<<endl;
            }
            else
            {
                cout << "sorry i can't find best in all" <<endl;
            }
        }
        else
        {
            if (stod(this->math_names[3][1]) < stod(this->experimental_names[3][1]) &&  stod(this->math_names[3][1]) < stod(this->human_names[3][1]))
            {
                cout << "Best in all is : " << this->math_names[3][0] << " with Score : " << this->math_names[3][1]<<endl;
            }
            else if (stod(this->experimental_names[3][1]) < stod(this->math_names[3][1]) && stod(this->experimental_names[3][1]) < stod(this->human_names[3][1]))
            {
                cout << "Best in all is : " << this->experimental_names[3][0] << " with Score : " << this->experimental_names[3][1]<<endl;
            }
            else if (stod(this->human_names[3][1]) < stod(this->math_names[3][1]) && stod(this->human_names[3][1]) < stod(this->experimental_names[3][1]))
            {
                cout << "Best in all is : " << this->human_names[3][0] << " with Score : " << this->human_names[3][1]<<endl;
            }
            else
            {
                cout << "sorry i can't find best in all" <<endl;
            }
        }
    }

    /**
     * what  = best | bad
     */
    void print_in_science(string what)
    {
        cout << "please enter one of this Science : "<< endl <<
        "1 - Math"<<endl<<
        "2 - Experimental"<<endl<<
        "3 - Human"<<endl;
        int type_science;
        cin >> type_science;
        switch (type_science)
        {
            case 1:
                if(what == "best")
                {
                    cout << "best in MathScience is : " << this->math_names[0][0] << " with Score : "<< this->math_names[0][1]<<endl;
                }
                else
                {
                    cout << "bad in MathScience is : " << this->math_names[3][0] << " with Score : "<< this->math_names[3][1]<<endl;
                }            
            break;
            case 2:
                if(what == "best")
                {
                    cout << "best in ExperimentalScience is : " << this->experimental_names[0][0] << " with Score : "<< this->experimental_names[0][1]<<endl;
                }
                else
                {
                    cout << "bad in ExperimentalScience is : " << this->experimental_names[3][0] << " with Score : "<< this->experimental_names[3][1]<<endl;
                }            
            break;
            case 3:
                if(what == "best")
                {
                    cout << "best in HumanScience is : " << this->human_names[0][0] << " with Score : "<< this->human_names[0][1]<<endl;
                }
                else
                {
                    cout << "bad in HumanScience is : " << this->human_names[3][0] << " with Score : "<< this->human_names[3][1]<<endl;
                }            
            break;
        
            default:
                cout<< "wrong input" << endl;
            break;
        }
    }

    /**
     * return is like : The best in `lessosn` is `name` with Score : `score`
     */
    string get_best_in_lesson(string lesson)
    {
        string science_array;
        int id = -1;
        int location;
        
        if (lesson == "math")
        {
            location = 0;
            if (id == -1)
            {
                id = 0;
                science_array = "math";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (science_array == "math")
                {
                   
                    if (this->math_numbers[i][location][1] > this->math_numbers[id][location][1])
                    {
                        science_array = "math";
                        id = i;
                    }

                    if (this->experimental_numbers[i][location][1] > this->math_numbers[id][location][1])
                    {
                        science_array = "experimental";   
                        id = i;
                    }
                }
                else
                {
                    if (this->math_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                    {
                        science_array = "math";
                        id = i;
                    }

                    if (this->experimental_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                    {
                        science_array = "experimental";   
                        id = i;
                    }
                    
                }
                
                
            }           
        }
        else if (lesson == "english")
        {
            location = 1;
            if (id == -1)
            {
                id = 0;
                science_array = "math";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (science_array == "math")
                {
                    if (this->math_numbers[i][location][1] > this->math_numbers[id][location][1])
                    {
                        science_array = "math";
                        id = i;
                    }

                    if (this->experimental_numbers[i][location][1] > this->math_numbers[id][location][1])
                    {
                        science_array = "experimental";   
                        id = i;
                    }
                    if (this->human_numbers[i][location][1] > this->math_numbers[id][location][1])
                    {
                        science_array = "human";   
                        id = i;
                    }
                }
                else if (science_array == "experimental")
                {
                    if (this->math_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                    {
                        science_array = "math";
                        id = i;
                    }

                    if (this->experimental_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                    {
                        science_array = "experimental";   
                        id = i;
                    }

                    if (this->human_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                    {
                        science_array = "human";   
                        id = i;
                    }
                }
                else
                {
                    if (this->math_numbers[i][location][1] > this->human_numbers[id][location][1])
                    {
                        science_array = "math";
                        id = i;
                    }

                    if (this->experimental_numbers[i][location][1] > this->human_numbers[id][location][1])
                    {
                        science_array = "experimental";   
                        id = i;
                    }
                    if (this->human_numbers[i][location][1] > this->human_numbers[id][location][1])
                    {
                        science_array = "human";   
                        id = i;
                    }
                }
                
            }           
        }
        else if (lesson == "geometry")
        {
            location = 2;
            if (id == -1)
            {
                id = 0;
                science_array = "math";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->math_numbers[i][location][1] > this->math_numbers[id][location][1])
                {
                    science_array = "math";   
                    id = i;
                }

            }           
        }
        else if (lesson == "equations")
        {
            location = 3;
            if (id == -1)
            {
                id = 0;
                science_array = "math";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->math_numbers[i][location][1] > this->math_numbers[id][location][1])
                {
                    science_array = "math";   
                    id = i;
                }

            }           
        }
        else if (lesson == "biology")
        {
            location = 2;
            if (id == -1)
            {
                id = 0;
                science_array = "experimental";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->experimental_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                {
                    science_array = "experimental";   
                    id = i;
                }

            }           
        }
        else if (lesson == "genetic")
        {
            location = 3;
            if (id == -1)
            {
                id = 0;
                science_array = "experimental";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->experimental_numbers[i][location][1] > this->experimental_numbers[id][location][1])
                {
                    science_array = "experimental";   
                    id = i;
                }

            }           
        }
        else if (lesson == "economy")
        {
            location = 0;
            if (id == -1)
            {
                id = 0;
                science_array = "human";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->human_numbers[i][location][1] > this->human_numbers[id][location][1])
                {
                    science_array = "human";   
                    id = i;
                }

            }           
        }
        else if (lesson == "philosophy")
        {
            location = 2;
            if (id == -1)
            {
                id = 0;
                science_array = "human";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->human_numbers[i][location][1] > this->human_numbers[id][location][1])
                {
                    science_array = "human";   
                    id = i;
                }

            }           
        }
        else if (lesson == "history")
        {
            location = 3;
            if (id == -1)
            {
                id = 0;
                science_array = "human";   
            }
            for (int i = 0; i < 5; i++)
            {
                if (this->human_numbers[i][location][1] > this->human_numbers[id][location][1])
                {
                    science_array = "human";   
                    id = i;
                }

            }           
        }
        else
        {
            return "Wrong";
        }


        std::stringstream output;
        if (science_array == "math")
        {
            output << "The best in " << lesson << " is " << this->math_names[id][0] << " with Score : " << this->math_numbers[id][location][1];
        }
        else if (science_array == "experimental")
        {

            output << "The best in " << lesson << " is " << this->experimental_names[id][0] << " with Score : " << this->experimental_numbers[id][location][1];
        }
        else
        {
            output << "The best in " << lesson << " is " << this->human_names[id][0] << " with Score : " << this->human_numbers[id][location][1];

        }
        return output.str().c_str();
                
    }

    void print_in_lesson()
    {
        cout << "please enter one of this lesson : "<< endl <<
        "1 - Math"<<endl<<
        "2 - English"<<endl<<
        "3 - Geometry"<<endl<<
        "4 - Equations"<<endl<<
        "5 - Biology"<<endl<<
        "6 - Genetic"<<endl<<
        "7 - Economy"<<endl<<
        "8 - History"<<endl<<
        "9 - Philosophy"<<endl;
        int type_lesson;
        cin >> type_lesson;

        switch (type_lesson)
        {
            case 1:
                cout<< get_best_in_lesson("math")<<endl;
                break;
            case 2:
                cout<< get_best_in_lesson("english")<<endl;
                break;
            case 3:
                cout<< get_best_in_lesson("geometry")<<endl;
                break;
            
            case 4:
                cout<< get_best_in_lesson("equations")<<endl;
                break;
            
            case 5:
                cout<< get_best_in_lesson("biology")<<endl;
                break;
            case 6:
                cout<< get_best_in_lesson("genetic")<<endl;
                break;
            case 7:
                cout<< get_best_in_lesson("economy")<<endl;
                break;
            case 8:
                cout<< get_best_in_lesson("history")<<endl;
                break;
            
            case 9:
                cout<< get_best_in_lesson("philosophy")<<endl;
                break;
            
            default:
                cout<< "Wrong input"<<endl;
                break;
        }
    }


    int print_by_name()
    {
        cout << "please enter the name like : Yalda Rasooli"<< endl;
        string name;
        getline(cin, name);

        for (int i = 0; i < 5; i++)
        {

            if (this->math_names[i][0] == name)
            {
                cout << this->math_names[i][0]<<"'s average is : " << this->math_names[i][1]<<endl;
                return 0;
            }
            else if (this->experimental_names[i][0] == name)
            {
                cout << this->experimental_names[i][0]<<"'s average is : " << this->experimental_names[i][1]<<endl;
                return 0;
            }
            else if (this->human_names[i][0] == name)
            {
                cout << this->human_names[i][0]<<"'s average is : " << this->human_names[i][1]<<endl;
                return 0;
            }
        }
        cout << "i can't find this name please attantion about `case sensitive`"<<endl;
        return 0;
    }
};



int main()
{

    Science science;
        /**
         *  Show Menu
         */ 
        cout << "Enter on of this numbers"<<endl<<
        "1 - Best Average in all"<<endl<<
        "2 - Best Average in special science"<<endl<<
        "3 - Bad Average in all"<<endl<<
        "4 - Bad Average in special science"<<endl<<
        "5 - Best number in lesson"<<endl<<
        "6 - show data by name and family"<<endl<<
        "7 - Exite"<<endl<<
        "8 - Show menu"<<endl;

    while(true)
    {

        int command;
        cin >> command;
        cin.clear();
        cin.get();
        
        switch(command)
        { 
            case 1: 
                science.print_in_all("best");
            break;
            case 2: 
                science.print_in_science("best");
            break;
            case 3: 
                science.print_in_all("bad");
            break;
            case 4: 
                science.print_in_science("bad");
            break;
            case 5: 
                science.print_in_lesson();
            break;
            case 6: 
                science.print_by_name();
            break;
            case 7: 
                /**
                 * Exite
                 */
                return 0;
            break; 
            case 8: 
                /**
                 *  Show Menu
                 */ 
                cout << "Enter on of this numbers"<<endl<<
                "1 - Best Average in all"<<endl<<
                "2 - Best Average in special science"<<endl<<
                "3 - Bad Average in all"<<endl<<
                "4 - Bad Average in special science"<<endl<<
                "5 - Best number in lesson"<<endl<<
                "6 - show data by name and family"<<endl<<
                "7 - Exite"<<endl<<
                "8 - Show menu"<<endl;

            break; 
        }
        
    }
    return 0;
}