# include <iostream>
# include <cstdlib>
# include <string>
# include <ctime>
using namespace std;

enum level { easy = 1, med, hard, mix };
enum operation_type { add = 1, sub, mux, divi, mix_operation };
struct game_data
{
	int num_of_questions;
    operation_type enoperation_type;
	string soperation_type;
	level level_game;
	string slevel_game;
	int num_of_correct_answers;
	int num_of_wrong_answers;
};

struct question_data
{
	int num1;
	int num2;
	int num_operation_type;
	int result;
};	

int read_times_play()
{
	int num = 0;
	cout << "How many quetions do you want to play???";
	cin >> num;
	return num;
}

int read_operation_type()
{
	int num = 0;
	cout << "Please enter operation type {1} Add {2} Sub {3} Mux {4} Div {5} Mix ???";
	cin >> num;
	return num;
}

int read_level_game()
{
	int num = 0;
	cout << "Please enter level of game {1} Easy {2} Med {3} Hard {4} Mix ???";
	cin >> num;
	return num;
}

int  read_answer()
{
	int num = 0;
	cin >> num;
	return num;
}

int random_num(int from, int to)
{
	int random = rand() % (to - from + 1) + from;
	return random;
}

int detecate_level(int level)
{
	switch (level)
	{
	case easy:
		return random_num(1, 10);
	case med:
		return random_num(10, 100);
	case hard:
		return random_num(100, 1000);

	
	}

}


int calculate_result(int operation_type, int num1, int num2)

{
	switch (operation_type)


	{
	 case add:

		return num1 + num2;

	case sub:

		return num1 - num2;

	case mux:

		return num1*num2;

	case divi:

		return num1 / num2;
	}

}

void check_answer(int answer, int result,int &correct_answers,int &wrong_answers)
{
	if (answer == result)
	{
		system("color 20");
		cout << "Correct answer :-)\n";
		correct_answers++;

	}
	else
	{
		system("color 4F");
		cout << "Wrong answer :-(\n";
		wrong_answers++;
	}
}

string detect_level_string(level enlevel_game)
{
	switch (enlevel_game)
	{
	case easy:
		return "Easy";
	case med:
		return "Med";
	case hard:
		return "Hard";
	case mix:
		return "Mix";
	}
}

string detect_operation_string(operation_type enoperation_type)
{
	switch (enoperation_type)
	{
	case add:
		return "Add";
	case sub:
		return "Sub";
	case mux:
		return "Mux";
	case divi:
		return "Div";
	case mix_operation:
		return "Mix";
	}
}
game_data read_game_data(int num_correct, int num_wrong,int num_of_questions, level enlevel_game, operation_type enoperation_type)
{

	game_data data;
	data.num_of_questions = num_of_questions;
	data.num_of_correct_answers = num_correct;
	data.num_of_wrong_answers = num_wrong;
	data.level_game = enlevel_game;
	data.slevel_game = detect_level_string(data.level_game);
	data.enoperation_type = enoperation_type;
	data.soperation_type = detect_operation_string(data.enoperation_type);

	return data;

}

void check_if_level_is_mix( level& current_level)
{
	

	if (current_level == mix)
	{
		current_level = (level)random_num(1, 3);
	}
}


void check_if_operation_is_mix(operation_type& current_operation)
{
	if (current_operation == mix_operation)
	{
		current_operation = (operation_type)random_num(1, 4);
	}
}

question_data read_question_data(question_data& question, level current_level, operation_type current_operation)
{
	question.num1 = detecate_level(current_level);
	question.num2 = detecate_level(current_level);
	question.num_operation_type = current_operation;
	question.result = calculate_result(question.num_operation_type, question.num1, question.num2);
	return question;
}

int  print_question_data(int num_question,int &num_of_correct_answers,int &num_of_wrong_answers, question_data question)
{

	int user_answer = 0;
	switch (question.num_operation_type)

	{
	case 1:
		cout << question.num1 << "\n +\n" << question.num2 << "\n" << "_____\n";
		user_answer = read_answer();


		break;

	case 2:
		cout << question.num1 << "\n -\n" << question.num2 << "\n" << "_____\n";
		user_answer = read_answer();
		break;

	case 3:
		cout << question.num1 << "\n *\n" << question.num2 << "\n" << "_____\n";
		user_answer = read_answer();
		break;

	case 4:

		cout << question.num1 << "\n / \n" << question.num2 << "\n" << "_____\n";
		user_answer = read_answer();
		break;

	}

	check_answer(user_answer, question.result, num_of_correct_answers, num_of_wrong_answers);

	return user_answer;
}

game_data print_questions_round( int num_of_questions, level enlevel_game,operation_type enoperation_type)

{

	question_data question;


	int num_of_correct_answers = 0;
	int num_of_wrong_answers = 0;
	
	


	for (int i = 1;i <= num_of_questions;i++)

	{   level current_level = enlevel_game;
	    operation_type current_operation = enoperation_type;

		check_if_level_is_mix(current_level);	
		check_if_operation_is_mix(current_operation);

		question = read_question_data(question, current_level, current_operation);

	   print_question_data(i, num_of_correct_answers, num_of_wrong_answers, question);

		
	}

	
	return read_game_data(num_of_correct_answers, num_of_wrong_answers,num_of_questions, enlevel_game,enoperation_type);



}

void reset_game()
{
	system("color 0F");
	system("cls");
	cout << "Welcome to the Math Game\n";
	cout << "-------------------\n";
}

void print_game_data(game_data data)
{
	cout << "Game Data:\n";
	cout << "-----------\n";
	cout << "Number of Questions: " << data.num_of_questions << "\n";
	cout << "Number of Correct Answers: " << data.num_of_correct_answers << "\n";
	cout << "Number of Wrong Answers: " << data.num_of_wrong_answers << "\n";
	cout << "Level: " << data.slevel_game << "\n";
	cout << "Operation: " << data.soperation_type << "\n";
}

	void play_game()
	{
	   int again;
		do
		
		{
			reset_game();
			int num_of_questions = read_times_play();
			int operation_num = read_operation_type();
			int level_num = read_level_game();

			

			game_data data = print_questions_round(  num_of_questions, (level)level_num, (operation_type)operation_num);


			print_game_data(data);



			cout << "Do you want to play again? [1] Yes [2] No ???\n";
			cin >> again;


		} while (again == 1);



	}



	int main()
	{
		srand((unsigned)time(NULL));
		play_game();
		return 0;
	}