from socket import *

host = "127.0.0.1"
port = 8080

http_server = socket(AF_INET, SOCK_STREAM)

http_server.setsockopt(
    SOL_SOCKET,
    SO_REUSEADDR,
    1
)

http_server.bind(
    (host, port)
)

http_server.listen(10)

print("Server Started")

while True:

    client, address = http_server.accept()

    request = client.recv(
        4096
    ).decode()

    try:

        request_line = request.split("\n")[0]

        url = request_line.split()[1]

        if url == "/":

            page = "index.html"

        else:

            page = url.replace(
                "/",
                ""
            )

        try:

            file = open(
                page,
                "r",
                encoding="utf-8"
            )

            html = file.read()

            file.close()

            response = (
                "HTTP/1.0 200 OK\r\n"
                "Content-Type:text/html\r\n"
                "\r\n"
                + html
            )

        except:

            response = (
                "HTTP/1.0 404 NOT FOUND\r\n"
                "\r\n"
                "<h1>NOT FOUND</h1>"
            )

        client.sendall(
            response.encode()
        )

    except:

        pass

    client.close()