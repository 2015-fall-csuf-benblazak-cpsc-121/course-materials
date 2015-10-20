#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    // ------------------------------------------------------------------------

    {
        cout << "// SECTION BEGIN if--bad\n";
        for (int a = 1;; a++) {
            if (a = 5) {
                cout << "a reached 5!\n";
                break;
            } else {
                cout << a << endl;
            }
        }
        cout << "// SECTION END if--bad\n";
    }
    {
        cout << "// SECTION BEGIN if--good\n";
        for (int a = 1;; a++) {
            if (a == 5) {
                cout << "a reached 5!\n";
                break;
            } else {
                cout << a << endl;
            }
        }
        cout << "// SECTION END if--good\n";
    }

    // ------------------------------------------------------------------------

goto end__or__bad;
    {
        cout << "// SECTION BEGIN or--bad\n";
        for(;;) {
            cout << "this is the loop that never ends\n"
                 << "it just goes on and on my friends\n"
                 << "some systems started running it\n"
                 << "not knowing what it was\n"
                 << "and they'll continue running it\n"
                 << "forever just because\n";

            cout << "would you like to continue? ";
            char answer;
            cin >> answer;
            if (answer == 'y' || 'Y')
                cout << "okay!\n";
            else
                break;
        }
        cout << "// SECTION END or--bad\n";
    }
end__or__bad:
goto end__or__good;
    {
        cout << "// SECTION BEGIN or--good\n";
        for(;;) {
            cout << "this is the loop that never ends\n"
                 << "it just goes on and on my friends\n"
                 << "some systems started running it\n"
                 << "not knowing what it was\n"
                 << "and they'll continue running it\n"
                 << "forever just because\n";

            cout << "would you like to continue? ";
            char answer;
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                cout << "okay!\n";
            else
                break;
        }
        cout << "// SECTION END or--good\n";
    }
end__or__good:

    // ------------------------------------------------------------------------

goto end__while__bad;
    {
        cout << "// SECTION BEGIN while--bad\n";
        int a = 5;
        while(a > 0);
            cout << a-- << " ";
        cout << endl;
        cout << "// SECTION END while--bad\n";
    }
end__while__bad:
    {
        cout << "// SECTION BEGIN while--good\n";
        int a = 5;
        while(a > 0)
            cout << a-- << " ";
        cout << endl;
        cout << "// SECTION END while--good\n";
    }

    // ------------------------------------------------------------------------

goto end__for__bad;
    {
        cout << "// SECTION BEGIN for--bad\n";
        for (int i = 0; i < 5; i--)
            cout << i << " ";
        cout << endl;
        cout << "// SECTION END for--bad\n";
    }
end__for__bad:
    {
        cout << "// SECTION BEGIN for--good\n";
        for (int i = 0; i < 5; i++)
            cout << i << " ";
        cout << endl;
        cout << "// SECTION END for--good\n";
    }

    // ------------------------------------------------------------------------

goto end__do_while__bad;
    {
        cout << "// SECTION BEGIN do-while--bad\n";
        int a = 3;
        do {
            cout << "do you wanna build " << a << " snow "
                 << ((a == 1) ? "man" : "men")
                 << "? :)\n";

        } while (a >= 1);
        cout << "// SECTION END do-while--bad\n";
    }
end__do_while__bad:
    {
        cout << "// SECTION BEGIN do-while--good\n";
        int a = 3;
        do {
            cout << "do you wanna build " << a << " snow "
                 << ((a == 1) ? "man" : "men")
                 << "? :)\n";
            a--;
        } while (a >= 1);
        cout << "// SECTION END do-while--good\n";
    }

    // ------------------------------------------------------------------------

    return 0;
}

