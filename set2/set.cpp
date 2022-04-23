#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

template<class T>
void Delete_repetition(std::vector<T> &my_set) {
    for (int i = 0; i < my_set.size() - 1; ++i) {
        if (my_set[i] == my_set[i + 1]) {
            my_set.erase(my_set.begin() + i);
            i--;
        }
    }

}


class My_set {
public:
    My_set() {}

    virtual My_set add(My_set &other) {
        return {};
    }

    virtual My_set mult(My_set &other) {
        return {};
    }

    virtual My_set sim_sub(My_set &other) {
        return {};
    }

    std::vector<int> my_set;
    std::vector<std::string> my_string_set;


};


class IntegerSet : public My_set {
public:
    explicit IntegerSet(const std::vector<int> &get) {
        my_set = get;
        std::sort(my_set.begin(), my_set.end());
        Delete_repetition(my_set);
    }

    My_set add(My_set &other) override {
        My_set res;
        for (int &i: my_set) {
            res.my_set.push_back(i);
        }
        for (int &i: other.my_set) {
            bool flag = 1;
            for (int j: my_set) {
                if (i == j) flag = 0;
            }
            if (flag == 1) res.my_set.push_back(i);
        }
        IntegerSet final(res.my_set);
        std::sort(final.my_set.begin(), final.my_set.end());
        Delete_repetition(final.my_set);
        return final;

    }

    My_set mult(My_set &set2) override {
            My_set res;
            try {

                for (int &i: set2.my_set) {
                    for (int j: my_set) {
                        if (i == j) res.my_set.push_back(i);
                    }
                }
                bool flag=0;
                for (int &i: set2.my_set) {
                    for (int j: my_set) {
                        if (i == j) flag=1;
                    }
                }
                if(flag==0) res.my_set={0};
            }

            catch (std::out_of_range){
                res.my_set = {};
            }
            IntegerSet final(res.my_set);
            std::sort(final.my_set.begin(), final.my_set.end());
            Delete_repetition(final.my_set);
            return final;

        }

    My_set sim_sub(My_set &other) {
        My_set res;
        for (int &i: other.my_set) {
            bool flag = 1;
            for (int j: my_set) {
                if (i == j) flag = 0;
            }
            if (flag == 1) {
                res.my_set.push_back(i);
            }
        }
        for (int &i: my_set) {
            bool flag = 1;
            for (int j: other.my_set) {
                if (i == j) flag = 0;
            }
            if (flag == 1) {
                res.my_set.push_back(i);
            }
        }
        IntegerSet final(res.my_set);
        std::sort(final.my_set.begin(), final.my_set.end());
        Delete_repetition(final.my_set);
        return final;

    }

};


class StringSet : public My_set {
public:
    StringSet(const std::vector<std::string> &get) {
        my_string_set = get;
        std::sort(my_string_set.begin(), my_string_set.end());
        Delete_repetition(my_string_set);
    }

    My_set add(My_set &other) override {
        My_set res;
        for (std::string &i: my_string_set) {
            res.my_string_set.push_back(i);
        }
        for (std::string &i: other.my_string_set) {
            bool flag = true;
            for (std::string j: my_string_set) {
                if (i == j) flag = false;
            }
            if (flag == 1) res.my_string_set.push_back(i);
        }
        StringSet final(res.my_string_set);
        std::sort(final.my_string_set.begin(), final.my_string_set.end());
        Delete_repetition(final.my_string_set);
        return final;

    }

    My_set mult(My_set &other) override {
            My_set res;
            try {
                for (std::string &i: other.my_string_set) {
                    for (std::string j: my_string_set) {
                        if (i == j) res.my_string_set.push_back(i);
                    }
                }
                bool flag=0;
                for (std::string &i: other.my_string_set) {
                    for (std::string j: my_string_set) {
                        if (i == j) flag=1;
                    }
                }
                if(flag==0) res.my_string_set={""};
            }
            catch (std::out_of_range){
                res.my_string_set = {};
            }
            StringSet final(res.my_string_set);
            std::sort(final.my_string_set.begin(), final.my_string_set.end());
            Delete_repetition(final.my_string_set);
            return final;

        }

    My_set sim_sub(My_set &other) {
        My_set res;
        for (std::string &i: other.my_string_set) {
            bool flag = true;
            for (std::string j: my_string_set) {
                if (i == j) flag = false;
            }
            if (flag == 1) {
                res.my_string_set.push_back(i);
            }
        }
        for (std::string &i: my_string_set) {
            bool flag = true;
            for (std::string j: other.my_string_set) {
                if (i == j) flag = false;
            }
            if (flag == 1) {
                res.my_string_set.push_back(i);
            }
        }
        StringSet final(res.my_string_set);
        std::sort(final.my_string_set.begin(), final.my_string_set.end());
        Delete_repetition(final.my_string_set);
        return final;

    }


};


