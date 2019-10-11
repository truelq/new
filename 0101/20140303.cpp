#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct options
{
    char option;
    int state = 0;
    string canshu;
};
int main()
{
    int lines;
    vector<string> cmdl;
    vector<options> opt;
    options opts;
    char temp[256];
    string content;

    cin >> content;
    cin >> lines;
    cin.get();
    for (int i = 0; i < lines; ++i)
    {
        cin.getline(temp, 256);
        cmdl.push_back(temp);
    }
    for (int i = 0; i < lines; ++i)
    {
        int flag = 0;
        for (int j = 0; j < cmdl[i].size(); j++)
        {
            if (cmdl[i][j] == ' ')
            {
                if (j + 1 < cmdl[i].size() && cmdl[i][j + 1] == '-')
                {
                    temp[0] = cmdl[i][j + 2];
                    flag = 0;
                    for (int k = 0; k < content.size(); k++)
                    {
                        if (content[k] == temp[0])
                        {
                            if (k + 1 < content.size() && content[k + 1] == ':')
                            {
                                flag = 1;
                                break;
                            }
                            else
                            {
                                flag = 2;
                                break;
                            }
                        }
                    }
                    if (flag == 1)
                    {
                        opts.option = temp[0];
                        if (j + 4 < cmdl[i].size() && cmdl[i][j + 4] != '-')
                        {
                            int h;

                            for (h = 0; h < cmdl[i].size(); ++h)
                            {
                                if (h + j + 4 < cmdl[i].size() && cmdl[i][h + j + 4] != ' ')
                                {
                                    temp[h] = cmdl[i][h + j + 4];
                                }
                                else
                                    break;
                            }
                            temp[h] = 0;
                            opts.canshu = temp;
                            opts.state = 1;
                            int r=0;
                            for (int g = 0; g < opt.size();++g){
                                if(opt[g].option==opts.option)
                                {
                                    if(opt[g].state)
                                    {opt[g].canshu = temp;
                                    r = 1;}
                                }
                            }
                            if(r==0)
                                opt.push_back(opts);
                            j = j + h + 3;
                        }
                        else
                            break;
                    }
                    else if (flag == 2)
                    {
                        opts.option = temp[0];
                        opts.state = 0;
                        opt.push_back(opts);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            
        }
        for (int j = 0; j < opt.size(); ++j)
        {
            for (int k = j; k < opt.size(); ++k)
            {
                if (opt[j].option > opt[k].option)
                {
                    opts = opt[j];
                    opt[j] = opt[k];
                    opt[k] = opts;
                }
            }
        }
        cout << "Case " << i + 1<<':';

        for (int j = 0; j < opt.size(); ++j)
        {
            if (j + 1 < opt.size()&&opt[j].option == opt[j + 1].option)
                continue;
            else
            {
                cout << " -";
                cout << opt[j].option;

                if (opt[j].state)
                {
                    cout << ' ' << opt[j].canshu;
                }
            }
        }
        cout << endl;
        opt.clear();
    }
    getchar();
    getchar();
    getchar();
}