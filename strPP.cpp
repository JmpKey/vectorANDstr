#include <iostream>

class Str
{
public:

    Str(const char* _st1, const char* _st2) {
        r_print(get_plus_st(_st1, _st2), get_search_st(_st1, _st2));
    }

    char* get_plus_st(const char* _in_st, const char* _new_st)
    {
        size_t ind2 = 0;
        tmp_p_arr = new char[strlen(_in_st) + strlen(_new_st) + 1];
        for (size_t i = 0; i < strlen(_in_st) + strlen(_new_st) + 1; i++) {
            if ((strlen(_in_st) + strlen(_new_st) + 1) == i) { tmp_p_arr[i] = '\0'; }
            else
            {
                if (i < strlen(_in_st)) { tmp_p_arr[i] = _in_st[i]; }
                else { tmp_p_arr[i] = _new_st[ind2]; ind2++; }
            }
        }
        return tmp_p_arr;
    }

    const char* get_search_st(const char* __in_st, const char* _search_st)
    {
        return strstr(__in_st, _search_st);
    }

    void r_print(char* _w_st1, const char* _w_st2) { printf("%s\n%s", _w_st1, _w_st2); }

    ~Str() { delete[] tmp_p_arr; };

private:
    char* tmp_p_arr = {};
};

int main()
{
    Str s_obj("SOS, from which this boring world will be stunned!", "world");

    return 0;
}