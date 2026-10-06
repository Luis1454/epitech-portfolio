#!/usr/bin/env python3

import sys
sys.path.append('IA')
import getopt
from client import ZappyAI

def main(argv):
    host = ''
    port = 0
    team_name = ''

    try:
        opts, args = getopt.getopt(argv, "p:n:h:", ["port=", "name=", "host="])
    except getopt.GetoptError as err:
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        sys.exit(2)

    for opt, arg in opts:
        if opt in ("-p", "--port"):
            port = int(arg)
        elif opt in ("-n", "--name"):
            team_name = arg
        elif opt in ("-h", "--host"):
            host = arg

    if not port or not team_name:
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        sys.exit(2)

    if not host:
        host = "localhost"

    client = ZappyAI(host, port, team_name)
    client.run()


if __name__ == "__main__":
    main(sys.argv[1:])
