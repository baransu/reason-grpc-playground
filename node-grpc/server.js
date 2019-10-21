let PROTO_PATH = __dirname + "/../protofiles/users.proto";

let grpc = require("grpc");
let protoLoader = require("@grpc/proto-loader");
let packageDefinition = protoLoader.loadSync(PROTO_PATH, {
  keepCase: true,
  longs: String,
  enums: String,
  defaults: true,
  oneofs: true
});

let hello_proto = grpc.loadPackageDefinition(packageDefinition).proto;

function createUser(call, callback) {
  callback(null, {
    user: {
      id: "user1",
      first_name: call.request.first_name,
      last_name: call.request.last_name
    }
  });
}

function readUser(call, callback) {
  callback(null, {
    user: {
      id: call.request.id,
      first_name: "tomasz",
      last_name: "cichocinski",
      date_of_birth: 0
    }
  });
}

function main() {
  let server = new grpc.Server();
  server.addService(hello_proto.UsersService.service, {
    createUser,
    readUser
  });
  server.bind("127.0.0.1:50051", grpc.ServerCredentials.createInsecure());
  server.start();
}

main();
