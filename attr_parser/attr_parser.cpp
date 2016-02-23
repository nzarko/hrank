// attr_parser.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<string> StringList;

namespace Alg {
	enum SplitBehavior { SkipEmptyParts, KeepEmptyParts };
	string join(const vector<string> &vec, char sep = ':');
	static StringList split(const string &str, const char &sep,
		Alg::SplitBehavior sb = Alg::SkipEmptyParts);
};

string Alg::join(const vector<string> &vec, char sep) {
	string res;
	for (size_t i = 0; i < vec.size(); i++)
		res += vec[i] + sep;
	return res;
}

StringList Alg::split(const string &str, const char &sep, Alg::SplitBehavior behavior) {
	vector<string> tr_list;
	string helper;
	int start = 0;
	int end;
	while ((end = str.find_first_of(sep, start)) != string::npos/*-1*/) {
		if (start != end || behavior == Alg::KeepEmptyParts)
		{
			helper = str.substr(start, end - start);
			tr_list.push_back(helper);
		}
		start = end + 1;
	}
	if (start != str.size() || behavior == Alg::KeepEmptyParts)
	{
		helper = str.substr(start);
		tr_list.push_back(helper);
	}
	return tr_list;
}

vector<StringList> process_queries(const StringList &queries)
{
	vector<StringList> queries_list;
	cout << "Queries list 1" << endl;
	for (size_t i = 0; i < queries.size(); i++) {
		StringList query_list = Alg::split(queries[i], '.');
		if (query_list.size() > 0) {
			StringList helper = Alg::split(query_list[query_list.size() - 1], '~');
			if (helper.size() > 1) {
				query_list[query_list.size() - 1] = helper[0];
				query_list.push_back(helper[1]);
			}
		}
		queries_list.push_back(query_list);
	}
	return queries_list;
}

string get_attributes(string hrml_string,string tag_name, string attr_name, size_t tag_position)
{
	string helper,res = "Not Found!";
	helper = hrml_string.substr(tag_position,tag_name.size());
	if (helper == tag_name) {
		size_t pos = hrml_string.find_first_of('>', tag_position);
		if (pos != string::npos)
		{
			helper = hrml_string.substr(tag_position, pos);
			pos = helper.find(attr_name);
			if (pos != string::npos)
			{
				pos = helper.find('=', pos);
				if (pos != string::npos)
				{
					pos = helper.find_first_of('"', pos);
					size_t end = helper.find_first_of('"', pos + 1);
					end -= pos + 1;
					res = helper.substr(pos + 1, end);
				}
			}
		}
	}
	return res;
}
string evaluate_query(const StringList &query,const string &hrml_string) 
{
	string res = "Not Found!";
	stack <string> query_stack;
	size_t len = query.size();
	string helper;
	//Fill in query_stack
	for (size_t i = 0; i < query.size(); i++)
		query_stack.push(query[i]);
	
	if (len == 2) { //Only one tag has specified
		//Search the attribute value
		/*helper = hrml_string.substr(1, query[0].size());
		if (helper == query[0]) {
			size_t pos = hrml_string.find_first_of('>', 0);
			if (pos != string::npos)
			{
				helper = hrml_string.substr(1, pos);
				pos = helper.find(query_stack.top());
				if (pos != string::npos)
				{
					pos = helper.find('=', pos);
					if (pos != string::npos)
					{
						pos = helper.find_first_of('"', pos);
						size_t end = helper.find_first_of('"', pos + 1);
						end -= pos + 1;
						res = helper.substr(pos + 1, end);
					}
				}
			}
		}*/
		res = get_attributes(hrml_string, query[0], query_stack.top(), 1);
	}
	if (len >= 3 ) 	{ //TODO : write the code
		vector<size_t> positions(2*(query.size() - 1), 0),tmp_vector;
		StringList both_ends_list = query;
		both_ends_list.pop_back();
		for (size_t i = 0; i < query.size() - 1; i++)
		{
			both_ends_list.push_back(query[i]);
			both_ends_list[i+ len-1].insert(0, "/");			
		}
		reverse(both_ends_list.begin() + len-1, both_ends_list.end());
		int cur_pos = 0;
		for (size_t i = 0; i < both_ends_list.size(); i++)
		{
			cur_pos = hrml_string.find(both_ends_list[i], cur_pos);
			positions[i] = cur_pos;
		}
		tmp_vector = positions;
		sort(tmp_vector.begin(), tmp_vector.end());
		if (tmp_vector  == positions )
		{
			size_t pos1 = hrml_string.find(query[len - 2]);
			res = get_attributes(hrml_string, query[len - 2], query[len - 1],
				pos1);
		}
	}

	return 	res;
}
ostream &operator << (ostream &os, const vector<string> &strs) {
	for (size_t i = 0; i < strs.size(); i++)
		os << strs[i] << endl;

	return os;
}

int main()
{
	int N, Q;
	string  hrml;
	string line;
	vector<string> queries;
	cin >> N >> Q;

	//Read the hrml lines.
	cin.ignore(100, '\n');
	for (int i = 1; i <= N; i++) {
		getline(cin, line);
		hrml += line;
	}

	//Read the Queries
	cin.clear();
	for (int i = 1; i <= Q; i++) {
		getline(cin, line);
		queries.push_back(line);
	}
	cout << "Hrml input : " << endl;
	cout << hrml << endl;

	cout << "Queries : " << endl;
	cout << queries << endl;

	vector<StringList> queries_list = process_queries(queries);
	cout << "query_list" << endl;
	for (size_t i = 0; i < queries_list.size(); i++)
	{
		cout << "Query " << (i + 1) << " : " << endl;
		cout << queries_list[i] << endl;
	}


	//finally find the tags values
	for (size_t i = 0; i < queries_list.size(); i++)
		cout << evaluate_query(queries_list[i], hrml) << endl;

	return 0;
}

