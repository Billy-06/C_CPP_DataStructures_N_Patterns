#include "Map.h"
#include "UniDirectionalList.h"
#include "BiDirectionalList.h"
#include "Enemy.h"
#include "Player.h"
#include "Stack.h"

using namespace std;

Map::Map()
{
	tileSpace = new TileSpace<Tile*>();

	vector<string> envNames = {
		"Grass", "Dirt", "Water", "Rock",
		"Sand", "Snow", "Ice", "Lava"
	};
	vector<string> charaNames = {
		"Player", "Player Muncher", "Player Chomper", "Big Boss"
	};
	vector<string> envDescription = {
		"[H] Green Material will make player itchy to death",
		"[N] Dark grainy material will supply player with minerals and health them",
		"[H] Clear Liquid will choke player's breath till the pass out",
		"[N] Hard material containing ores will boost players health and weapon strength",
		"[H] Light grainy material will drown the player till they run out of breath",
		"[N] White material that healths the player's wounds and boosts health",
		"[H] Clear solid material that'll pierce into the player killing them instantly",
		"[N] Read hot metal semi-viscous fluid that's brandish the player's weapons and boost their strength"
	};

	auto* env_one = new Environ(envNames[0], envDescription[0], true, 15, 0) ;
	auto* env_two = new Environ(envNames[1], envDescription[1], false, 0, 10);
	auto* env_three = new Environ(envNames[2], envDescription[2], true, 8, 0);
	auto* env_four = new Environ(envNames[3], envDescription[3], false, 0, 14);
	auto* env_five = new Environ(envNames[4], envDescription[4], true, 5, 0);
	auto* env_six = new Environ(envNames[5], envDescription[5], false, 0, 25);
	auto* env_seven = new Environ(envNames[6], envDescription[6], true, 30, 0);
	auto* env_eight = new Environ(envNames[7], envDescription[7], false, 0, 22);

	environs = {
		env_one, env_two, env_three, env_four, env_five, env_six, env_seven, env_eight
	};

	Player* player = new Player(charaNames[0], 100, 100);
	Enemy* playerMuncher = new Enemy(charaNames[1], 100, 100);
	Enemy* playerChomper = new Enemy(charaNames[2], 100, 100);
	Enemy* bigBoss = new Enemy(charaNames[3], 200, 300);

	characters = {
		player, playerMuncher, playerChomper, bigBoss
	};
}

Map::Map(TileSpace<Tile*>* tSpace, std::vector<Environ*>& env, std::vector<Character*>& chrcters)
{
	tileSpace = tSpace;
	environs = env;
	characters = chrcters;
}

Map::~Map()
{
	delete tileSpace;
}

std::vector<Environ*> Map::GetEnviron() const
{
	return environs;
}

std::vector<Character*> Map::GetCharacters() const
{
	return characters;
}

void Map::DemoUnidirectional() const
{
	cout << "Demo Unidirectional" << endl;
	UniDirectionalList<Environ> queue = UniDirectionalList<Environ>();

	for (auto* env : environs) 
	{
		auto* node = new QueueNode<Environ>(env);
		queue.Append(node);
	}
	queue.Remove(1);
	QueueNode<Environ>* current = queue.GetFirstNode();
	cout << "UnShuffle Linked List" << endl;
	cout << "===================" << endl;
	while (current->GetNext() != nullptr) 
	{
		Environ envNode = *current->GetItem();
		envNode.Print();
		current = current->GetNext();
	}

	current = queue.GetFirstNode();
	queue.Shuffle();
	cout << "Shuffle Linked List" << endl;
	cout << "===================" << endl;
	while (current->GetNext() != nullptr) 
	{
		Environ envNode = *current->GetItem();
		envNode.Print();
		cout << queue.GetFirstNode()->GetItem()->GetName()
		<< " Node Popped" << endl;

		queue.Pop();
		cout << endl;
		current = current->GetNext();
	}
}

void Map::DemoTrees() const
{
	ActionTree* tree = new ActionTree();
	cout << "InOrder Traversal of the Tree" << endl;
	cout << "=============================" << endl;
	tree->InOrderTraverse();
	cout << "PreOrder Traversal of the Tree" << endl;
	cout << "==============================" << endl;
	tree->PreOrderTraverse();
	cout << "PostOrder Traversal of the Tree" << endl;
	cout << "===============================" << endl;
	tree->PostOrderTraverse();
}

void Map::DemoBidirectional() const
{
	cout << "Demo Bidirectional" << endl;
	Player* player = new Player(*characters[0]);
	Enemy* playerMuncher = new Enemy(*characters[1]);

	string date = "23/12/2020";
	std::vector<string> playerThreats = {
		"I'll make you pay for what you've done",
		"You'll regret crossing me",
		"I'll destroy you and everything you stand for",
		"You're going down",
		"I'll make sure you never forget this",
		"You're messing with the wrong person",
		"I'll crush you like a bug",
	};
	Message newMsg = Message(player, playerMuncher, playerThreats[0], date);
	player->SetMessages(newMsg);
	for (auto& threat : playerThreats)
	{
		player->SendMessage(playerMuncher, threat);
	}
	player->ShowMessages();
	// playerMuncher->ShowMessages();

}

void Map::DemoStack() const
{
	Stack<Environ> stack = Stack<Environ>();

	for (auto* env : environs)
	{
		auto* node = new QueueNode<Environ>(env);
		stack.Push(node);
	}

	while (!stack.IsEmpty())
	{
		Environ envNode = *stack.Peek()->GetItem();
		envNode.Print();
		cout << stack.Peek()->GetItem()->GetName()
			<< " Node Popped" << endl;

		stack.Pop();
		cout << endl;
	}

	cout << "===============================" << endl;
	cout << "Stack is now Empty !!" << endl;
	cout << "===============================" << endl;
	cout << "Adding new Environ to the stack" << endl;
	cout << "===============================" << endl;

	string name = "Oasis", name2 = "Volcano", name3 = "Cave";
	string description = "[N] Region for the player to hydrate and refresh",
		 description2 = "[H] Region for the player to burn and get reborn",
		 description3 = "[H] Region for the player to get lost and fight for his way out";

	Environ* env_one = new Environ(name, description, false, 0, 10);
	Environ* env_two = new Environ(name2, description2, true, 15, 0);
	Environ* env_three = new Environ(name3, description3, true, 20, 0);

	stack.Push(new QueueNode<Environ>(env_one));
	stack.Push(new QueueNode<Environ>(env_two));
	stack.Push(new QueueNode<Environ>(env_three));

	while (!stack.IsEmpty())
	{
		Environ envNode = *stack.Peek()->GetItem();
		envNode.Print();
		cout << stack.Peek()->GetItem()->GetName()
			<< " Node Popped" << endl;

		stack.Pop();
		cout << endl;
	}
}

void Map::DemoIterators() const
{
	cout << "Player Backpack" << endl;
	Backpack* playerBackpack = characters[0]->GetBackpack();
	playerBackpack->Display();

	Iterator1D<Item> itemBag = playerBackpack->GetItemBag();
	Iterator1D<Weapon> weaponBag = playerBackpack->GetWeaponBag();

	std::cout << "Player's Backpack" << std::endl;
	std::cout << "==================" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		itemBag[i].Print();
	}

	std::cout << "Player's Weapons Pack" << std::endl;
	std::cout << "=====================" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		weaponBag[i].Print();
	}

}

void Map::ClearConsole() const
{
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
		system("cls");
	#elif __APPLE__
		system("clear");
	#elif __linux__
		system("clear");
	#endif
}

void Map::ShowEnviron() const
{
	for (auto* env : environs)
	{
		env->Print();
	}
}

void Map::ShowCharacters() const
{
	for (auto* character : characters)
	{
		character->ShowStats();
	}
}

void Map::Fight()
{
	bool fighting = true;

	string response;
	while (fighting)
	{
		ShowCharacters();
		cout << "Who would you like to fight?" << endl;
		getline(cin, response);

		if (response == "menu")
		{
			cout << "You go back to the menu" << endl;
		}
		else if (response == "main menu")
		{
			ClearConsole();
			cout << "You go back to the menu" << endl;
			break;
		}
		else if (response == "quit")
		{
			cout << "You quit the game" << endl;
			fighting = false;
		}
		else
		{
			cout << "Invalid command. Please try again. Type 'help' to get some assistance" << endl;
		}

	}
}

void Map::TakeCommands()
{
	const Map* map = new Map();
	bool playing = true;

	while (playing)
	{
		cout << "Enter a command: ";
		string command;
		getline(cin, command);

		
		if (command == "help")
		{
			cout << "Commands: " << endl;
			cout << "\thelp - \t\tdisplays this message" << endl;
			cout << "\tenvs - \t\tShows the environment Items in the game" << endl;
			cout << "\tquit - \t\tdisplays the current room" << endl;
			cout << "\tchars - \t\tShows Characters in the game" << endl;
			cout << "\tfight - \t\topens a door" << endl;
			cout << "\ttrees - \t\tDemonstrates the tree data structures" << endl;
			cout << "\tclear - \t\tclears the screen" << endl;
			cout << "\tunidirectional - \t\tDemonstrates a Unidirectional List" << endl;
			cout << "\tbidirectional - \t\tDemonstrates a Bidirectional List" << endl;
			cout << "\tstack - \t\tDemonstrates a Stack Data Structure" << endl;
			cout << "\titerators - \t\tDemonstrates the implementation of an Iterator" << endl;
			cout << "\texamine - \t\texamines" << endl;
		}
		else if (command == "quit")
		{
			cout << "Goodbye!" << endl;
			playing = false;
		}
		else if (command == "envs")
		{
			map->ShowEnviron();
		}
		else if (command == "chars")
		{
			map->ShowCharacters();
		}
		else if (command == "fight")
		{
			cout << "You open the door and see a monster!" << endl;
			cout << "You fight the monster and win!" << endl;
		}
		else if (command == "trees")
		{
			cout << "Action Trees" << endl;
			map->DemoTrees();
		}
		else if (command == "clear")
		{
			map->ClearConsole();
		}
		else if (command == "unidirectional")
		{
			map->DemoUnidirectional();
		}
		else if (command == "bidirectional")
		{
			map->DemoBidirectional();
		}
		else if (command == "iterators")
		{
			map->DemoIterators();
		}
		else if (command == "stack")
		{
			map->DemoStack();
		}
		else
		{
			cout << "Invalid command. Please try again. Type 'help' to get some assistance" << endl;
		}
	}


}

void Map::Begin()
{
	cout << "Welcome to the game!" << endl;
	cout << "Type 'help' for a list of commands." << endl;
	
	TakeCommands();
}