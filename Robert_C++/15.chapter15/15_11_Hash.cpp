#include "15_11_Hash.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

typedef Hash<string, string> Setting;

int main() {
    map<string, int> m;
    multimap<string, int> mm; // キーの重複が許される連想配列

    // 値の追加
    m["one"] = 1;
    m["two"] = 2;
    m.insert( map<string, int>::value_type("two", 2) ); // としても同じ
    cout << m.size() << endl; //=> 2 (キーの重複が許されなかったため 3 とはならない)

    // multimap の場合は重複可能性があるため [] 演算子は使用できません
    mm.insert( multimap<string, int>::value_type("one", 1) );
    mm.insert( multimap<string, int>::value_type("one", -1) );
    cout << mm.size() << endl; //=> 2


    // 値の参照
    cout << m["one"] << endl; //=> 1
    for(map<string, int>::iterator it = m.begin(), end = m.end(); it != end; ++it) {
        cout << it->first << ": " << it->second << endl; //=> one: 1
    }                                                    //   two: 2

    for(multimap<string, int>::iterator it = mm.begin(), end = mm.end(); it != end; ++it) {
        cout << it->first << ": " << it->second << endl; //=> one: 1
    }                                                    //   one: -1

    // 該当キーの要素数
    cout << m.count("one") << endl; //=> 1
    cout << mm.count("one") << endl; //=> 2


    // 値の検索
    map<string, int>::iterator it = m.find("one");
    if ( it != m.end() ) { // 見つからなければ m.end() が返されます
        cout << "found: (" << it->first << ", " << it->second << ")" << endl; //=> found: (one, 1)
    }

    multimap<string, int>::iterator it_ = mm.find("one");
    if ( it_ != mm.end() ) {
        cout << "found" << endl; //=> found
    }

    // 値の削除
    cout << m.erase("one") << endl; //=> 1 (削除された要素数)
    cout << m.erase("not_exist") << endl; //=> 0 (存在しない要素の場合)
    cout << m.size() << endl; //=> 1

    cout << mm.erase("one") << endl; //=> 2
    cout << mm.size() << endl; //=> 0

    // 全削除
    m.clear();
    mm.clear();
    cout << boolalpha
         << m.empty() << endl //=> true
         << mm.empty() << endl; //=> true

    return 0;
}