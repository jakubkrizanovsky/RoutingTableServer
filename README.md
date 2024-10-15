# RoutingTableServer

## Project Overview
This project implements a TCP web server that listens on port 8080 and displays the routing table of the host machine as an HTML table. The server reads the routing table from the virtual file `/proc/net/route` and presents the information in a formatted HTML table.

The routing table is presented with the following columns:
- Interface: The identifier of the network interface.
- Destination: The destination address (IPv4), e.g., 172.20.0.0.
- Mask: The CIDR subnet mask (IPv4), e.g., 255.255.0.0.
- Metric: The metric (integer value >= 0) associated with the route, e.g., 100.
- Gateway: The gateway IP address (IPv4), e.g., 172.20.1.254. The gateway address is highlighted in the output.
- Flags: Flags related to the route, e.g., whether the route is active, or if the gateway is used.

## Build and Run Instructions
### Prerequisites
To build and run this project, you will need:
- A Linux operating system (any distribution).
- g++ compiler with support for C++17.
- Make (build system).
- pthread library for threading support (included in most Linux distributions).
- Access to the `/proc/net/route` file (available on Linux systems).

### Step-by-Step Instructions
1. Clone the Repository
```
git clone https://github.com/jakubkrizanovsky/RoutingTableServer.git
cd RoutingTableServer
```

2. Build the Application
The application is built using make, which compiles the C++ source files and generates the executable.

To build the application, simply run:

```
make
```

This will:
- Create the `bin/` directory if it doesn't exist.
- Compile the C++ source files in the `src/` directory.
- Link the necessary libraries and generate the executable main in the `bin/` directory.

3. Run the Application
After successfully building the application, you can run the TCP server with the following command:
```
make run
```

This will:
- Build the application (if not already built).
- Clear the terminal.
- Start the TCP server on port 8080.


4. Access the Server
To access the server, open a web browser and navigate to http://localhost:8080. The routing table will be displayed in an HTML table format.

### Cleaning Up
To clean up the build files, you can run:

```
make clean
```
This will remove the `bin/` directory and all compiled files.

## Project Structure
The project is structured as follows:

```
.
├── include/          # Header files
├── src/              # Source code
├── bin/              # Compiled binary (generated after build)
├── Makefile          # Makefile for building the project
└── README.md         # Project documentation
```

## Example HTML Output
When accessed through a browser, the TCP server will return an HTML page displaying the routing table:
```
<html><table>
        <tr><th>Interface</th><th>Destination</th><th>Mask</th><th>Metric</th><th>Gateway</th><th>Flags</th></tr>
        <tr><td>eth0</td><td>0.0.0.0</td><td>0.0.0.0</td><td>208</td><td><strong>10.0.1.254</strong></td><td>3</td></tr>
        <tr><td>eth0</td><td>10.0.1.0</td><td>255.255.255.0</td><td>0</td><td><strong>0.0.0.0</strong></td><td>1</td></tr>
</table></html>
```


## License
This project is licensed under the MIT License.