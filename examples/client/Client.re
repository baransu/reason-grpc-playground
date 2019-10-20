open Lwt.Infix;

module UsersProto = Proto.Users.Proto;

let client = () => {
  let%bind connection = Lib.Client.create(~host="localhost", ~port=50051, ());

  let userId = "b9ca41e9-9ce9-4852-8b11-c6386cfb0e25";

  let%map response =
    Grpc.Users.UsersService.Client.readUser(connection, {id: userId});

  Console.log(response.user);
};

client() |> Lwt_main.run;
