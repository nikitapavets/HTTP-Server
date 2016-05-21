#include "Interface.h"

string Interface::getSeparators(const int count, const char sep) {

	string sleshe="";

	for (int i = 0; i < count; i++) {
		sleshe += sep;
	}

	return sleshe;
}

string Interface::GetMenuItem(const int size, const char* value, const char sep='|') {

	string menu_item = "";
	stringstream ss;

	int space_offset=0;
	if (!((strlen(value) % 2 != 0) && (size % 2 != 0))) {
		space_offset = 1;
	}
	if ((size == 4)) {
		space_offset = -1;
	}

	int space_size;
	space_size = (LINE_SIZE * size - BORDER * 2 - size - 1 + space_offset  - strlen(value)) / 2;

	ss << this->getSeparators(LINE_SIZE * size - size - 1 + space_offset, sep) << endl;
	ss << this->getSeparators(BORDER, sep);
	ss << this->getSeparators(space_size, ' ');
	if ((strlen(value) % 2 != 0)) {
		ss << " ";
	}
	ss << value;
	ss << this->getSeparators(space_size, ' ');
	ss << this->getSeparators(BORDER, sep) << endl;
	ss << this->getSeparators(LINE_SIZE * size - size - 1 + space_offset, sep) << endl;

	menu_item = ss.str();

	return menu_item;
}

string Interface::GetMenuItem(const vector<string> value, const char sep = '|') {

	string menu_item = "";
	stringstream ss;
	int space_size;

	ss << getSeparators(LINE_SIZE * value.size() - BORDER * (value.size() -1), sep) << endl;

	ss << this->getSeparators(BORDER, sep);
	for (int i = 0; i < value.size(); i++) {
		space_size = (LINE_SIZE - BORDER * 2 - value[i].length()) / 2;
		ss << this->getSeparators(space_size, ' ');
		if (value[i].length() % 2 != 0) {
			ss << " ";
		}
		ss << value[i];
		ss << this->getSeparators(space_size, ' ');
		ss << this->getSeparators(BORDER, sep);
	}
	ss << endl;

	ss << getSeparators(LINE_SIZE * value.size() - BORDER * (value.size() - 1), sep) << endl;

	menu_item = ss.str();

	return menu_item;
}

void Interface::GetMainMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Main menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Users");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Domains");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Pages");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Shut down");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			this->GetUsersMenu();
			break;
		}
		case 2: {
			this->GetDomainsMenu();
			break;
		}
		case 3: {
			this->GetPrivatePagesMenu();
			break;
		}
		case 4: {
#ifdef _MSC_VER
			HANDLE hExit = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, TRUE, EXIT_EVENT);
			SetEvent(hExit);
#endif
			break;
		}
		default: {
			this->GetMainMenu();
		}
	}
}

void Interface::GetUsersMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Users menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show users");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			this->AddUser();
			this->GetUsersMenu();
			break;
		}
		case 2: {
			this->RemoveUser();
			this->GetUsersMenu();
			break;
		}
		case 3: {
			PrintUsers();
			system("pause");
			this->GetUsersMenu();
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetUsersMenu();
		}
	}
}

void Interface::GetDomainsMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Domains menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add domain");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove domain");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show domains");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			this->AddDomain();
			this->GetDomainsMenu();
			break;
		}
		case 2: {
			this->RemoveDomain();
			this->GetDomainsMenu();
			break;
		}
		case 3: {
			this->PrintDomains();
			system("pause");
			this->GetDomainsMenu();
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetDomainsMenu();
		}
	}
}

void Interface::GetPrivatePagesMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Private pages menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add private page");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove private page");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show private page");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			this->AddPage();
			system("pause");
			this->GetPrivatePagesMenu();
			break;
		}
		case 2: {
			this->RemovePage();
			system("pause");
			this->GetPrivatePagesMenu();
			break;
		}
		case 3: {
			this->PrintPages();
			system("pause");
			this->GetPrivatePagesMenu();
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetPrivatePagesMenu();
		}
	}
}

int Interface::GetSelectedItem() {

	int n;

	cout << "# NUMBER: ";
	cin >> n;

	return n;
}

void Interface::PrintUsers() {

	system("cls");

	dbUsers cli;
	cli.SelectUsers();
	list<Users> users = cli.GetUsers();

	vector<string> columns;
	columns.push_back("id");
	columns.push_back("login");
	columns.push_back("password");

	cout << this->GetMenuItem(3, "Users") << endl;
	cout << this->GetMenuItem(columns) << endl;

	list<Users>::iterator it;

	for (it = users.begin(); it != users.end(); it++) {

		columns.clear();
		stringstream ss;
		ss << it->id;
		string id;
		ss >> id;
		columns.push_back(id);
		columns.push_back(it->login);
		columns.push_back(it->password);

		cout << this->GetMenuItem(columns) << endl;
	}

}

bool Interface::AddUser() {

	cout << "# ADD USER" << endl;
	cout << "## LOGIN: ";
	string login;
	cin >> login;
	cout << "## PASSWORD: ";
	string password;
	cin >> password;

	dbUsers cli;
	return cli.AddUser(login, password);
}

bool Interface::RemoveUser() {

	cout << "# REMOVE USER" << endl;
	cout << "## LOGIN: ";
	string login;
	cin >> login;

	dbUsers cli;
	return cli.RemoveUser(login);
}

void Interface::PrintDomains() {

	system("cls");

	dbDomains dom;
	dom.SelectDomains();
	list<Domains> domains = dom.GetDomains();

	vector<string> columns;
	columns.push_back("id");
	columns.push_back("domain");

	cout << this->GetMenuItem(2, "Domains") << endl;
	cout << this->GetMenuItem(columns) << endl;

	list<Domains>::iterator it;

	for (it = domains.begin(); it != domains.end(); it++) {

		columns.clear();
		stringstream ss;
		ss << it->id;
		string id;
		ss >> id;
		columns.push_back(id);
		columns.push_back(it->domain);

		cout << this->GetMenuItem(columns) << endl;
	}

}

bool Interface::AddDomain() {

	cout << "# ADD DOMAIN" << endl;
	cout << "## DOMAIN: ";
	string domain;
	cin >> domain;

	dbDomains dom;
	return dom.AddDomain(domain);
}

bool Interface::RemoveDomain() {

	cout << "# REMOVE DOMAIN" << endl;
	cout << "## DOMAIN: ";
	string domain;
	cin >> domain;

	dbDomains dom;
	return dom.RemoveDomain(domain);
}

bool Interface::AddPage() {

	cout << "# ADD PRIVATE PAGE" << endl;

	cout << "## DOMAIN: ";
	string domain;
	cin >> domain;

	cout << "## PRIVATE PAGE: ";
	string page;
	cin >> page;

	cout << "## ACCESS LEVEL [1-3]: ";
	int access_level;
	cin >> access_level;

	if ((access_level < 1) || access_level > 3) {
		cout << "Access level should be in range [1-3]." << endl;
		return false;
	}

	stringstream ss;
	ss << "domain = ";
	ss << "'";
	ss << domain;
	ss << "' LIMIT 1";
	string sql = ss.str();

	dbDomains dom;
	dom.SelectDomains(sql);
	list<Domains> domains = dom.GetDomains();
	list<Domains>::iterator it;

	dbPages pg;
	if (domains.size() == 1) {
		it = domains.begin();
		if (it->id) {
			if (pg.AddPage(page, access_level, it->id)) {
				cout << "Private page was added." << endl;
				return true;
			}
		}
	}
	else {
		cout << "Unknown domain name." << endl;
	}

	return false;
}

bool Interface::RemovePage() {

	cout << "# REMOVE PRIVATE PAGE" << endl;

	cout << "## DOMAIN: ";
	string domain;
	cin >> domain;

	cout << "## PRIVATE PAGE: ";
	string page;
	cin >> page;

	stringstream ss;
	ss << "domain = ";
	ss << "'";
	ss << domain;
	ss << "' LIMIT 1";
	string sql = ss.str();

	dbDomains dom;
	dom.SelectDomains(sql);
	list<Domains> domains = dom.GetDomains();
	list<Domains>::iterator it;

	dbPages pg;
	if (domains.size() == 1) {
		it = domains.begin();
		if (it->id) {
			if (pg.RemovePage(page, it->id)) {
				cout << "Private page was removed." << endl;
				return true;
			}
		}
	}
	else {
		cout << "Unknown domain name." << endl;
	}

	return false;
}

void Interface::PrintPages() {

	system("cls");

	dbPages pg;
	pg.SelectPages();
	list<PrivatePage> pages = pg.GetPages();

	vector<string> columns;
	columns.push_back("id");
	columns.push_back("page");
	columns.push_back("access_level");
	columns.push_back("domain_id");

	cout << this->GetMenuItem(4, "Private pages") << endl;
	cout << this->GetMenuItem(columns) << endl;

	list<PrivatePage>::iterator it;

	for (it = pages.begin(); it != pages.end(); it++) {

		columns.clear();
		stringstream ss;
		ss << it->id;
		string tmp;
		ss >> tmp;
		columns.push_back(tmp);
		columns.push_back(it->page);
		ss.clear();
		tmp.clear();
		ss << it->access_level;
		ss >> tmp;
		columns.push_back(tmp);
		ss.clear();
		tmp.clear();
		ss << it->domain_id;
		ss >> tmp;
		columns.push_back(tmp);

		cout << this->GetMenuItem(columns) << endl;
	}

}