#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

void usage(void)
{
    fprintf(stderr, "Usage: cipher <shift> <msg>\n\n");
    fprintf(stderr, "Example: cipher 10 \"hello world\"\n");
    exit(1);
}

int main(int argc, char **argv)
{
    std::string msg, result;
    int shift;

    if (argv[1] == NULL || argv[2] == NULL) {
        usage();
    }

    shift = atoi(argv[1]);
    msg = argv[2];

    for (int i = 0; i < msg.size(); i++) {
        result += (msg[i] - 'Z' + shift) % 26 + 'Z';
    }

    transform(result.begin(), result.end(), result.begin(), ::toupper);
    std::cout << result << std::endl;
    return 0;
}
