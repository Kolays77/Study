from notion.client import NotionClient

# Obtain the `token_v2` value by inspecting your browser cookies on a logged-in session on Notion.so
client = NotionClient(token_v2="234871937431aecdbb0971712d85624689bf7d1411b909da0f9a872f19b3f0785470bd24f041b6a6d5208dae8cd8f9d166893aa93ec61506aa534f5abea623f75799b93931c59bc58c81769d0a7a")

# Replace this URL with the URL of the page you want to edit
page = client.get_block("https://www.notion.so/Getting-Started-3962929d13c0407f81c226bf18fecc17")

# Note: You can use Markdown! We convert on-the-fly to Notion's internal formatted text data structure.
page.title = "EEEEE"