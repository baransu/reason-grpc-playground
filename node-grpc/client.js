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

function main() {
  let client = new hello_proto.UsersService(
    "localhost:50051",
    grpc.credentials.createInsecure()
  );

  client.waitForReady(Number.POSITIVE_INFINITY, error => {
    client.readUser({ id: "123" }, function(err, response) {
      if (err) {
        console.log(err);
        client.readUser({ id: "123" }, function(err, response) {
          if (err) {
            throw err;
          }
          console.log("User:", response.user);
        });
      } else {
        console.log("User:", response.user);
      }
    });
  });
}

main();
